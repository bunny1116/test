Begin
create table #result
(pepid int,CustomerName varchar(150),UserName varchar(150),ChangedFields varchar(500))
--select distinct pepid into #temp1 from CDDGEcn where EndDate is null and EcnSeqNo!=1
select Gpep.PepId,Gpep.PepLevelId,Gpep.PepTypeId,cust.CustomerName,Gpep.RequestorComments,
Gpep.PepDeterminationComments,Gpep.BookingOfficeId,cust.CustomerStatus,Gpep.CreatedTS,
cust.EntityName,
cust.CustomerId, ISNULL(guser.FirstName,'') + ' '+ ISNULL(guser.LastName,'') as UserName into #temp1
from CDDGpep Gpep
join CDDGCustomer cust
on Gpep.CustomerId=cust.CustomerId
left join CDDGUser guser
on guser.LanId =Gpep.CreatedBy
where Gpep.PepId = @PepId_HistLog
DECLARE @PepId INT, @PeplevelId int =0 ,@PepType varchar(100),@CustomerId int,
@PepDetComments varchar(max),
@RequesterComments varchar(max),@BookingOfcId int,
@CustomerName varchar(200),@UserName varchar(200),
@PrimaryPepAssociationId int,@CountryBSAApprovalId int,@EntityName varchar(255)
DECLARE PepCURSOR CURSOR FOR
select pepid, PepLevelId,PepTypeId,CustomerId,CustomerName,UserName,
 PepDeterminationComments,RequestorComments,BookingOfficeId,EntityName
from #temp1
OPEN PepCURSOR
FETCH NEXT FROM PepCURSOR INTO @PepId, @PeplevelId,@PepType,@CustomerId,@CustomerName,
                   @UserName,@PepDetComments,@RequesterComments,@BookingOfcId,@EntityName
WHILE (@@FETCH_STATUS=0) 
BEGIN
-- PeplevelId,peptype, customerid history checking
declare  @PepLevelIdHist int = 0 ,@PepTypeHist varchar(100),@CustomerIdHist int,
@PepDetCommentsHist varchar(max),
@RequesterCommentsHist varchar(max),@BookingOfcIdHist int
declare @ChangedFieldName varchar(max)
select top 1 @PepLevelIdHist=pephist.PepLevelId,@PepTypeHist = pephist.PepTypeId,
@CustomerIdHist = pephist.CustomerId, @PepDetCommentsHist=PepDeterminationComments,
@BookingOfcIdHist=BookingOfficeId,
@RequesterCommentsHist=RequestorComments
 from CDDGPepHistory pephist 
where pephist.PepId = @PepId
order by pephist.CreatedTS desc

declare @HistCount int
select @HistCount = count(*) from CDDGPepHistory pephist where pephist.PepId = @PepId

if(@HistCount > 0 )
begin
 if(@PeplevelId is null) set @PeplevelId=0
if(@PepLevelIdHist is null) set @PepLevelIdHist=0
--peplvelid 
if(@PepLevelIdHist <> @PeplevelId)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PepLevelId'
else
set @ChangedFieldName ='PepLevelId'
end
if(@PepType is null) set @PepType=0
if(@PepTypeHist is null) set @PepTypeHist=0
--peptypid
if(@PepTypeHist <> @PepType)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PepType'
else
set @ChangedFieldName ='PepType'
end

if(@CustomerId is null) set @CustomerId=0
if(@CustomerIdHist is null) set @CustomerIdHist=0
--CustomerId
--if(@CustomerIdHist <> @CustomerId)
--begin
declare @CustmerStatusId int,@CustomerHistoryId int,@EntityNameHist varchar(255)
declare @CustmerName varchar(255),@CustomerNamehist varchar(255) 
declare @EntityFormationCountry int,@EntityFormationCountryhist int 
declare @FirstName varchar(255), @FirstNameHist varchar(255)
declare @LastName varchar(255), @LastNameHist varchar(255)
declare @IndividualAKAName varchar(255), @IndividualAKANameHist varchar(255)
declare @IndividualCitizenshipCountry int,@IndividualCitizenshipCountryHist int
declare @CustCountryBsaApprovalId int,@CustCountryBsaApprovalIdHist int
select @CustmerStatusId=CustomerStatus,@CustmerName=CustomerName,
 @EntityFormationCountry=EntityFormationCountry,@FirstName=IndividualFirstName,
 @LastName=IndividualLastName ,@IndividualAKAName= IndividualAKAName ,
 @IndividualCitizenshipCountry=IndividualCitizenshipCountry,
 @CustCountryBsaApprovalId=CountryBsaApprovalId from CDDGCustomer where CustomerId=@CustomerId
select @CustomerHistoryId=CustomerStatus,@CustomerNamehist=CustomerName,
@EntityNameHist=EntityName,@FirstNameHist=IndividualFirstName, @LastNameHist=IndividualLastName ,
@EntityFormationCountryhist=EntityFormationCountry ,@IndividualAKANameHist =IndividualAKAName ,
@IndividualCitizenshipCountryHist =IndividualCitizenshipCountry,
@CustCountryBsaApprovalId=CountryBsaApprovalId from CDDGCustomer where CustomerId=@CustomerIdHist
--customerStatus
if(@CustmerStatusId is null) set @CustmerStatusId=''
if(@CustomerHistoryId is null) set @CustomerHistoryId=''
if(@CustmerStatusId <> @CustomerHistoryId)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'Customer Status'
else
set @ChangedFieldName ='Customer Status'
end
--Customer Name
if(@CustmerName is null) set @CustmerName=''
if(@CustomerNamehist is null) set @CustomerNamehist=''
if(@CustmerName <> @CustomerNamehist)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'Customer Name'
else
set @ChangedFieldName ='Customer Name'
end
--Entity Name
if(@EntityName is null) set @EntityName=''
if(@EntityNameHist is null) set @EntityNameHist=''
if(@EntityName <> @EntityNameHist)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'Entity Name'
else
set @ChangedFieldName ='Entity Name'
end
--Entity Formation Country
if(@EntityFormationCountry is null) set @EntityFormationCountry=0
if(@EntityFormationCountryhist is null) set @EntityFormationCountryhist=0
if(@EntityFormationCountry <> @EntityFormationCountryhist)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'Entity Formation Country'
else
set @ChangedFieldName ='Entity Formation Country'
end
--First Name
if(@FirstName is null) set @FirstName=''
if(@FirstNameHist is null) set @FirstNameHist=''
if(@FirstName <> @FirstNameHist)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'Customer FirstName'
else
set @ChangedFieldName ='Customer FirstName'
end
--Last Name
if(@LastName is null) set @LastName=''
if(@LastNameHist is null) set @LastNameHist=''
if(@LastName <> @LastNameHist)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'Customer LastName'
else
set @ChangedFieldName ='Customer LastName'
end
--AKA Name
if(@IndividualAKAName is null) set @IndividualAKAName=''
if(@IndividualAKANameHist is null) set @IndividualAKANameHist=''
if(@IndividualAKAName <> @IndividualAKANameHist)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'IndividualAKAName'
else
set @ChangedFieldName ='IndividualAKAName'
end
--Individual citizenship country
if(@IndividualCitizenshipCountry is null) set @IndividualCitizenshipCountry=0
if(@IndividualCitizenshipCountryHist is null) set @IndividualCitizenshipCountryHist=0
if(@IndividualCitizenshipCountry <> @IndividualCitizenshipCountryHist)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'IndividualCitizenshipCountry'
else
set @ChangedFieldName ='IndividualCitizenshipCountry'
end
--Country BSA ApprovalId
if(@CustCountryBsaApprovalId is null) set @CustCountryBsaApprovalId=0
if(@CustCountryBsaApprovalIdHist is null) set @CustCountryBsaApprovalIdHist=0
if(@CustCountryBsaApprovalId <> @CustCountryBsaApprovalIdHist)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'IndividualAKAName'
else
set @ChangedFieldName ='IndividualAKAName'
end
--end
--PepDetermaniation Comment
if(@PepDetComments is null) set @PepDetComments=''
if(@PepDetCommentsHist is null) set @PepDetCommentsHist=''
if(@PepDetCommentsHist <> @PepDetComments)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PepDeterminationComments'
else
set @ChangedFieldName ='PepDeterminationComments'
end
--RequesterComments Comment
if(@RequesterComments is null) set @RequesterComments=''
if(@RequesterCommentsHist is null) set @RequesterCommentsHist=''
if(@RequesterCommentsHist <> @RequesterComments)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'RequesterComments'
else
set @ChangedFieldName ='RequesterComments'
end
--BookingOfc Id Comment
if(@BookingOfcId is null) set @BookingOfcId=0
if(@BookingOfcIdHist is null) set @BookingOfcIdHist=0
if(@BookingOfcIdHist <> @BookingOfcId)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'Booking Office'
else
set @ChangedFieldName ='Booking Office'
end
--Lob pep
 declare @LobPepId int, @LobPepIdHist int
 select @LobPepId=LobId from CDDGLobPep where PepId=@PepId and enddate is null
 select @LobPepIdHist=LobId from CDDGLobPep where PepId=@PepId and enddate is not null order by CreatedTS desc
 if(@LobPepId is null) set @LobPepId=0
if(@LobPepIdHist is null) set @LobPepIdHist=0
if(@LobPepIdHist <> @LobPepId)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'Line of business'
else
set @ChangedFieldName ='Line of business'
end

--CDDGPrimary Pep Table
select * into #CDDGPrimaryPep1 from CDDGPrimaryPep where EndDate is null and PepId=@PepId
select * into #CDDGPrimaryPep2 from CDDGPrimaryPep where EndDate is not null and PepId=@PepId
--PepPrimary
;with ctePrimary as
(
select 
(CASE WHEN C.PrimaryPepAssociationId IS NOT NULL AND D.PrimaryPepAssociationId IS NULL THEN 'INSERTED'
WHEN C.PrimaryPepAssociationId IS NULL AND D.PrimaryPepAssociationId IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status', 1 as StatusType  from #CDDGPrimaryPep1 c full join #CDDGPrimaryPep2 d
on c.PrimaryPepAssociationId=d.PrimaryPepAssociationId 
union all
select 
(CASE WHEN C.CountryBSAApprovalId IS NOT NULL AND D.CountryBSAApprovalId IS NULL THEN 'INSERTED'
WHEN C.CountryBSAApprovalId IS NULL AND D.CountryBSAApprovalId IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status', 2 as StatusType  from #CDDGPrimaryPep1 c full join #CDDGPrimaryPep2 d
on c.CountryBSAApprovalId=d.CountryBSAApprovalId
union all
select 
(CASE WHEN C.FirstName IS NOT NULL AND D.FirstName IS NULL THEN 'INSERTED'
WHEN C.FirstName IS NULL AND D.FirstName IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status', 3 as StatusType 
from #CDDGPrimaryPep1 c full join #CDDGPrimaryPep2 d
on c.FirstName = d.FirstName
union all
select
(CASE WHEN C.LastName IS NOT NULL AND D.LastName IS NULL THEN 'INSERTED'
WHEN C.LastName IS NULL AND D.LastName IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status', 4 as StatusType 
from #CDDGPrimaryPep1 c full join #CDDGPrimaryPep2 d
on c.LastName = d.LastName
union all
select
(CASE WHEN C.AKAName IS NOT NULL AND D.AKAName IS NULL THEN 'INSERTED'
WHEN C.AKAName IS NULL AND D.AKAName IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status', 5 as StatusType 
from #CDDGPrimaryPep1 c full join #CDDGPrimaryPep2 d
on c.AKAName = d.AKAName
union all
select
(CASE WHEN C.PrimaryPepCountryId IS NOT NULL AND D.PrimaryPepCountryId IS NULL THEN 'INSERTED'
WHEN C.PrimaryPepCountryId IS NULL AND D.PrimaryPepCountryId IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status', 6 as StatusType 
from #CDDGPrimaryPep1 c full join #CDDGPrimaryPep2 d
on c.PrimaryPepCountryId = d.PrimaryPepCountryId
union all
select
(CASE WHEN C.CountryBSAApprovalId IS NOT NULL AND D.CountryBSAApprovalId IS NULL THEN 'INSERTED'
WHEN C.CountryBSAApprovalId IS NULL AND D.CountryBSAApprovalId IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status', 7 as StatusType 
from #CDDGPrimaryPep1 c full join #CDDGPrimaryPep2 d
on c.CountryBSAApprovalId = d.CountryBSAApprovalId
union all
select
(CASE WHEN C.PrimaryPepPositionId IS NOT NULL AND D.PrimaryPepPositionId IS NULL THEN 'INSERTED'
WHEN C.PrimaryPepPositionId IS NULL AND D.PrimaryPepPositionId IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status', 8 as StatusType 
from #CDDGPrimaryPep1 c full join #CDDGPrimaryPep2 d
on c.PrimaryPepPositionId = d.PrimaryPepPositionId
union all
select
(CASE WHEN C.PrimaryPepAssociationId IS NOT NULL AND D.PrimaryPepAssociationId IS NULL THEN 'INSERTED'
WHEN C.PrimaryPepAssociationId IS NULL AND D.PrimaryPepAssociationId IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status', 9 as StatusType 
from #CDDGPrimaryPep1 c full join #CDDGPrimaryPep2 d
on c.PrimaryPepAssociationId = d.PrimaryPepAssociationId
union all
select
(CASE WHEN C.PrimaryPepAssociatedCountryId IS NOT NULL AND D.PrimaryPepAssociatedCountryId IS NULL THEN 'INSERTED'
WHEN C.PrimaryPepAssociatedCountryId IS NULL AND D.PrimaryPepAssociatedCountryId IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status', 10 as StatusType 
from #CDDGPrimaryPep1 c full join #CDDGPrimaryPep2 d
on c.PrimaryPepAssociatedCountryId = d.PrimaryPepAssociatedCountryId
union all
select
(CASE WHEN C.AssociatedCountryBSAApprovalId IS NOT NULL AND D.AssociatedCountryBSAApprovalId IS NULL THEN 'INSERTED'
WHEN C.AssociatedCountryBSAApprovalId IS NULL AND D.AssociatedCountryBSAApprovalId IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status', 11 as StatusType 
from #CDDGPrimaryPep1 c full join #CDDGPrimaryPep2 d
on c.AssociatedCountryBSAApprovalId = d.AssociatedCountryBSAApprovalId
)
select Status, StatusType INTO #tempPrimary FROM ctePrimary
declare @PrimarypepCount int
 select @PrimarypepCount =Count(*) from CDDGPrimaryPep where EndDate is null and PepId=@PepId
declare @UpdaatedPrimaryCount int,@insteredPrimaryCount int
select @UpdaatedPrimaryCount=count(*) from #tempPrimary where status='UPDATED' and StatusType=1
select @insteredPrimaryCount=count(*) from #tempPrimary where status='INSERTED' and StatusType=1
if( @UpdaatedPrimaryCount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPepAssociationId Updated'
else
set @ChangedFieldName ='PrimaryPepAssociationId Updated'
end
if(@UpdaatedPrimaryCount > 0 and @insteredPrimaryCount > 0 
and @UpdaatedPrimaryCount != @insteredPrimaryCount and @PrimarypepCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPepAssociationId Inserted'
else
set @ChangedFieldName ='PrimaryPepAssociationId Inserted'
end
--bsa approval
declare @UpdaatedBSACount int,@insteredBSACount int
select @UpdaatedBSACount=count(*) from #tempPrimary where status='UPDATED' and StatusType =2
select @insteredBSACount=count(*) from #tempPrimary where status='INSERTED' and StatusType =2
if( @UpdaatedBSACount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'CountryBSAApprovalId Updated'
else
set @ChangedFieldName ='CountryBSAApprovalId Updated'
end
if(@UpdaatedBSACount > 0 and @insteredBSACount > 0 
and @UpdaatedBSACount != @insteredBSACount and @PrimarypepCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'CountryBSAApprovalId Inserted'
else
set @ChangedFieldName ='CountryBSAApprovalId Inserted'
end
 
--PrimaryPep FirstName Count
declare @UpdatedFirstNameCount int,@InsertedFirstNameCount int
select @UpdatedFirstNameCount=count(*) from #tempPrimary where status='UPDATED' and StatusType=3
select @InsertedFirstNameCount=count(*) from #tempPrimary where status='INSERTED' and StatusType=3
if( @UpdatedFirstNameCount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPep FirstName Updated'
else
set @ChangedFieldName ='PrimaryPep FirstName Updated'
end
if(@UpdatedFirstNameCount > 0 and @InsertedFirstNameCount > 0 
and @UpdatedFirstNameCount != @InsertedFirstNameCount and @PrimarypepCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPep FirstName Inserted'
else
set @ChangedFieldName ='PrimaryPep FirstName Inserted'
end
--PrimaryPep LastName Count
declare @UpdatedLastNameCount int,@InsertedLastNameCount int
select @UpdatedLastNameCount=count(*) from #tempPrimary where status='UPDATED' and StatusType=4
select @InsertedLastNameCount=count(*) from #tempPrimary where status='INSERTED' and StatusType=4
if( @UpdatedLastNameCount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPep LastName Updated'
else
set @ChangedFieldName ='PrimaryPep LastName Updated'
end
if(@UpdatedLastNameCount > 0 and @InsertedLastNameCount > 0 
and @UpdatedLastNameCount != @InsertedLastNameCount and @PrimarypepCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPep LastName Inserted'
else
set @ChangedFieldName ='PrimaryPep LastName Inserted'
end
--PrimaryPep AKAName Count
declare @UpdatedAKANameCount int,@InsertedAKANameCount int
select @UpdatedAKANameCount=count(*) from #tempPrimary where status='UPDATED' and StatusType=5
select @InsertedAKANameCount=count(*) from #tempPrimary where status='INSERTED' and StatusType=5
if( @UpdatedAKANameCount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPep AKAName Updated'
else
set @ChangedFieldName ='PrimaryPep AKAName Updated'
end
if(@UpdatedAKANameCount > 0 and @InsertedAKANameCount > 0 
and @UpdatedAKANameCount != @InsertedAKANameCount and @PrimarypepCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPep AKAName Inserted'
else
set @ChangedFieldName ='PrimaryPep AKAName Inserted'
end
--PrimaryPep PrimaryPepCountryId Count
declare @UpdatedPrimaryPepCountryIdCount int,@InsertedPrimaryPepCountryIdCount int
select @UpdatedPrimaryPepCountryIdCount=count(*) from #tempPrimary where status='UPDATED' and StatusType=6
select @InsertedPrimaryPepCountryIdCount=count(*) from  #tempPrimary where status='INSERTED' and StatusType=6
if( @UpdatedPrimaryPepCountryIdCount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPepCountryId Updated'
else
set @ChangedFieldName ='PrimaryPepCountryId Updated'
end
if(@UpdatedPrimaryPepCountryIdCount > 0 and @InsertedPrimaryPepCountryIdCount > 0 
and @UpdatedPrimaryPepCountryIdCount != @InsertedPrimaryPepCountryIdCount and @PrimarypepCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPepCountryId Inserted'
else
set @ChangedFieldName ='PrimaryPepCountryId Inserted'
end
--PrimaryPep CountryBSAApprovalId Count
declare @UpdatedCountryBSAApprovalIdCount int,@InsertedCountryBSAApprovalIdCount int
select @UpdatedCountryBSAApprovalIdCount=count(*) from #tempPrimary where status='UPDATED' and StatusType=7
select @InsertedCountryBSAApprovalIdCount=count(*) from #tempPrimary where status='INSERTED' and StatusType=7
if( @UpdatedCountryBSAApprovalIdCount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPep CountryBSAApprovalId Updated'
else
set @ChangedFieldName ='PrimaryPep CountryBSAApprovalId Updated'
end
if(@UpdatedCountryBSAApprovalIdCount > 0 and @InsertedCountryBSAApprovalIdCount > 0 
and @UpdatedCountryBSAApprovalIdCount != @InsertedCountryBSAApprovalIdCount and @PrimarypepCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPep CountryBSAApprovalId Inserted'
else
set @ChangedFieldName ='PrimaryPep CountryBSAApprovalId Inserted'
end
----PrimaryPep PrimaryPepPositionId Count
declare @UpdatedPrimaryPepPositionIdCount int,@InsertedPrimaryPepPositionIdCount int
select @UpdatedPrimaryPepPositionIdCount=count(*) from #tempPrimary where status='UPDATED' and StatusType=8
select @InsertedPrimaryPepPositionIdCount=count(*) from #tempPrimary where status='INSERTED' and StatusType=8
if( @UpdatedPrimaryPepPositionIdCount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPepPositionId Updated'
else
set @ChangedFieldName ='PrimaryPepPositionId Updated'
end
if(@UpdatedPrimaryPepPositionIdCount > 0 and @InsertedPrimaryPepPositionIdCount > 0 
and @UpdatedPrimaryPepPositionIdCount != @InsertedPrimaryPepPositionIdCount and @PrimarypepCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPepPositionId Inserted'
else
set @ChangedFieldName ='PrimaryPepPositionId Inserted'
end
----PrimaryPep LastName Count
declare @UpdatedPrimaryPepAssociationIdCount int,@InsertedPrimaryPepAssociationIdCount int
select @UpdatedPrimaryPepAssociationIdCount=count(*) from #tempPrimary where status='UPDATED' and StatusType=9
select @InsertedPrimaryPepAssociationIdCount=count(*) from #tempPrimary where status='INSERTED' and StatusType=9
if( @UpdatedPrimaryPepAssociationIdCount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPepAssociationId Updated'
else
set @ChangedFieldName ='PrimaryPepAssociationId Updated'
end
if(@UpdatedPrimaryPepAssociationIdCount > 0 and @InsertedPrimaryPepAssociationIdCount > 0 
and @UpdatedPrimaryPepAssociationIdCount != @InsertedPrimaryPepAssociationIdCount and @PrimarypepCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPepAssociationId Inserted'
else
set @ChangedFieldName ='PrimaryPepAssociationId Inserted'
end
----PrimaryPep LastName Count
declare @UpdatedPrimaryPepAssociatedCountryIdCount int,@InsertedPrimaryPepAssociatedCountryIdCount int
select @UpdatedPrimaryPepAssociatedCountryIdCount=count(*) from  #tempPrimary where status='UPDATED' and StatusType=10
select @InsertedPrimaryPepAssociatedCountryIdCount=count(*) from #tempPrimary where status='INSERTED' and StatusType=10
if( @UpdatedPrimaryPepAssociatedCountryIdCount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPepAssociatedCountryId Updated'
else
set @ChangedFieldName ='PrimaryPepAssociatedCountryId Updated'
end
if(@UpdatedPrimaryPepAssociatedCountryIdCount > 0 and @InsertedPrimaryPepAssociatedCountryIdCount > 0 
and @UpdatedPrimaryPepAssociatedCountryIdCount != @InsertedPrimaryPepAssociatedCountryIdCount and @PrimarypepCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'PrimaryPepAssociatedCountryId Inserted'
else
set @ChangedFieldName ='PrimaryPepAssociatedCountryId Inserted'
end
----PrimaryPep AssociatedCountryBSAApprovalId Count
declare @UpdatedAssociatedCountryBSAApprovalIdCount int,@InsertedAssociatedCountryBSAApprovalIdCount int
select @UpdatedAssociatedCountryBSAApprovalIdCount=count(*) from #tempPrimary where status='UPDATED' and StatusType=11
select @InsertedAssociatedCountryBSAApprovalIdCount=count(*) from #tempPrimary where status='INSERTED' and StatusType=11
if( @UpdatedAssociatedCountryBSAApprovalIdCount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'AssociatedCountryBSAApprovalId Updated'
else
set @ChangedFieldName ='AssociatedCountryBSAApprovalId Updated'
end
if(@UpdatedAssociatedCountryBSAApprovalIdCount > 0 and @InsertedAssociatedCountryBSAApprovalIdCount > 0 
and @UpdatedAssociatedCountryBSAApprovalIdCount != @InsertedAssociatedCountryBSAApprovalIdCount and @PrimarypepCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'AssociatedCountryBSAApprovalId Inserted'
else
set @ChangedFieldName ='AssociatedCountryBSAApprovalId Inserted'
end
--ECN
;with cte5 as(
select * from CDDGEcn where EndDate is null
and PepId=@PepId),
cte6 as(
select * from CDDGEcn where EndDate is not null
and PepId=@PepId)
select 
(CASE WHEN C.Ecn IS NOT NULL AND D.Ecn IS NULL THEN 'INSERTED'
WHEN C.Ecn IS NULL AND D.Ecn IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status' into #tempEcn from cte5 c full join cte6 d
on c.Ecn=d.Ecn 
declare @EcnCount int
select @EcnCount =Count(*) from CDDGEcn where EndDate is null and PepId=@PepId
declare @UpdaatedECNCount int,@insteredECNCount int
select @UpdaatedECNCount=count(*) from #tempEcn where status='UPDATED'
select @insteredECNCount=count(*) from #tempEcn where status='INSERTED'
if( @UpdaatedECNCount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'ECN Updated'
else
set @ChangedFieldName ='ECN Updated'
end
if(@UpdaatedECNCount > 0 and @insteredECNCount > 0 
and @UpdaatedECNCount != @insteredECNCount and @EcnCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'ECN Inserted'
else
set @ChangedFieldName ='ECN Inserted'
end

--ISFlagged
;with cte7 as(
select * from CDDGEcn where EndDate is null
and PepId=121),
cte8 as(
select * from CDDGEcn where EndDate is not null
and PepId=121)
select 
(CASE WHEN C.IsFlagged IS NOT NULL AND D.IsFlagged IS NULL THEN 'INSERTED'
WHEN C.IsFlagged IS NULL AND D.IsFlagged IS NOT NULL THEN 'UPDATED'
ELSE 'NOCHANGE' 
END
) as 'Status' into #tempIsflagged from cte7 c full join cte8 d
on c.IsFlagged=d.IsFlagged 
declare @UpdaatedIsFlaggedCount int,@insteredIsFlaggedCount int
select @UpdaatedIsFlaggedCount=count(*) from #tempIsflagged where status='UPDATED'
select @insteredIsFlaggedCount=count(*) from #tempIsflagged where status='INSERTED'
if( @UpdaatedIsFlaggedCount > 0)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'IsFlagged Updated'
else
set @ChangedFieldName ='IsFlagged Updated'
end
if(@UpdaatedIsFlaggedCount > 0 and @insteredIsFlaggedCount > 0 
and @UpdaatedIsFlaggedCount != @insteredIsFlaggedCount AND @EcnCount > 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'IsFlagged Inserted'
else
set @ChangedFieldName ='IsFlagged Inserted'
end
--ECN not provided
declare @ECNNotProvided bit
select @ECNNotProvided=PrimaryECNNotProvided from CDDGEcn where PepId=@PepId
if(@ECNNotProvided is not null and @ECNNotProvided = 1)
begin
if(@ChangedFieldName != '')
set @ChangedFieldName =@ChangedFieldName +','+ 'ECNNotProvided'
else
set @ChangedFieldName ='ECNNotProvided'
end
drop table #tempPrimary
drop table #tempEcn
drop table #tempIsflagged
drop table #CDDGPrimaryPep1
drop table #CDDGPrimaryPep2
end
if(@ChangedFieldName != '')
begin
if not exists(select * from #result where pepid=@PepId)
begin
insert into #result(pepid,CustomerName,UserName,ChangedFields)
values(@PepId,@CustomerName,@UserName,@ChangedFieldName)
end
else
begin
declare @ChangedFiledsPeplevel varchar(500)
select @ChangedFiledsPeplevel=ChangedFields from #result where PepId=@PepId
IF (@ChangedFiledsPeplevel is null or CHARINDEX(@ChangedFieldName, @ChangedFiledsPeplevel) <= 0 )
begin
update #result set ChangedFields =@ChangedFiledsPeplevel + ',' + @ChangedFieldName where PepId=@PepId
end
end
end
set @ChangedFieldName = ''

FETCH NEXT FROM PepCURSOR INTO @PepId, @PeplevelId,@PepType,@CustomerId,@CustomerName,@UserName 
              ,@PepDetComments,@RequesterComments,@BookingOfcId,@EntityName
END
CLOSE PepCURSOR 
DEALLOCATE PepCURSOR
select * from #result
drop table #result
drop table #temp1
End
