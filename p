USE [CDDG]
GO
/****** Object:  StoredProcedure [dbo].[Weekly_Canned]    Script Date: 5/16/2017 3:03:32 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER Procedure [dbo].[Weekly_Canned] 
@FromDate DateTime ,
@ToDate DateTime
as
Begin
with cte as
(
select cr.PepId,cust.CustomerName,cr.RequestorComments,cust.CustomerStatus,cr.CreatedTS,
cr.ChangeRequestId,cust.CustomerId, guser.FirstName +' '+ guser.LastName as UserName,
cust.CountryBSAApprovalId
from CDDGChangeRequest cr
join CDDGCustomer cust
on cr.CustomerId=cust.CustomerId
left join CDDGUser guser
on guser.UserID =cr.UserId
where cr.CreatedTS between dateadd(day, 1-datepart(dw, @FromDate), CONVERT(date,@FromDate))
and dateadd(day, 7-datepart(dw, @ToDate), CONVERT(date,@ToDate))
)
select cte.PepId,cte.CustomerName,cte.RequestorComments,cte.UserName
from cte
join CDDGpep pep
on pep.PepId=cte.PepId
where not exists (select 1 from CDDGCustomer cust where
cust.CustomerId=pep.Customerid and cust.CustomerStatus=cte.CustomerStatus)
or not exists (select 1 from CDDGCustomer cust where
cust.CustomerId=pep.Customerid and cust.CountryBSAApprovalId=cte.CountryBSAApprovalId)
or exists (select 1 from CDDGEcn where PepId=pep.PepId and
ChangeRequestId=cte.ChangeRequestId
group by PepId,ChangeRequestId having COUNT(1) > 1
or count(Ecn) = 0 or count(IsFlagged) >=1)
or exists (select 1 from CDDGPrimaryPep Ppep
where PepId=cte.PepId and ChangeRequestId is null
and cte.ChangeRequestId in (
select ChangeRequestId from CDDGPrimaryPep Ppep1 where
Ppep1.PepId=cte.PepId and
Ppep1.PepId=Ppep.PepId and Ppep1.ChangeRequestId=cte.ChangeRequestId
and Ppep.PepRequestStatusId != Ppep1.PepRequestStatusId
)
)
order by cte.ChangeRequestId desc
End
