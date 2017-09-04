 
--exec GetGeneralInfoSearch 'gana',null,'gana', @filter ='Contains'
alter PROCEDURE GetGeneralInfoSearch
 @RequstedBy VARCHAR(50)= null,
 @AgentTIN varchar(50)=null,
 @RequestNumber varchar(50)=null,
 @SALegalName varchar(50)=null,
 @RequstedDate varchar(50)=null,
 @SAnumber varchar(50)=null,
 @MasterAccountName varchar(50)=null,
 @SACaseID int=null,
 @MasterAccountTIN varchar(50)=null,
 @filter varchar(50),
 @userid varchar(50)=null

AS
BEGIN
	 if(@filter = 'Contains')
	 begin
	    select * from CDDGSAGeneralInfo where Requested_By like  '%' + @RequstedBy + '%'  
		                                   or Request_Number like '%' + @RequestNumber + '%' 
										   or Sub_Account_Agent_Legal_Name like '%' + @SALegalName + '%' 
										   --or RequstedDate like '%' + @RequstedDate + '%' 
										   or Sub_Account_Number like '%' + @SAnumber + '%' 
										   or Sub_Account_Master_Account_Name like '%' + @MasterAccountName + '%' 
										   or Case_Id like '%' + CAST(@SACaseID AS NVARCHAR) + '%' 
										   or Sub_Account_Master_Account_TIN like '%' + @MasterAccountTIN + '%' 
	 end
	 if(@filter = 'StartsWith')
	 begin
	    select * from CDDGSAGeneralInfo where Requested_By like  '' + @RequstedBy + '%'  
		                                   or Request_Number like '' +  @RequestNumber + '%' 
										   or Sub_Account_Agent_Legal_Name like '' +  @SALegalName + '%' 
										   --or RequstedDate like '' +  @RequstedDate + '%' 
										   or Sub_Account_Number like '' +  @SAnumber + '%' 
										   or Sub_Account_Master_Account_Name like '' +  @MasterAccountName + '%' 
										   or Case_Id like '' +   CAST(@SACaseID AS NVARCHAR) + '%' 
										   or Sub_Account_Master_Account_TIN like '' +  @MasterAccountTIN + '%' 
	 end
	 if(@filter = 'StartsWith')
	 begin
	    select * from CDDGSAGeneralInfo where Requested_By like  '' + @RequstedBy + '%'  
		                                   or Request_Number like '' +  @RequestNumber + '%' 
										   or Sub_Account_Agent_Legal_Name like '' +  @SALegalName + '%' 
										   --or RequstedDate like '' +  @RequstedDate + '%' 
										   or Sub_Account_Number like '' +  @SAnumber + '%' 
										   or Sub_Account_Master_Account_Name like '' +  @MasterAccountName + '%' 
										   or Case_Id like '' +   CAST(@SACaseID AS NVARCHAR) + '%' 
										   or Sub_Account_Master_Account_TIN like '' +  @MasterAccountTIN + '%' 
	 end
	 if(@filter = 'EndsWith')
	 begin
	     select * from CDDGSAGeneralInfo where Requested_By like  '%' + @RequstedBy + ''  
		                                   or Request_Number like '%' + @RequestNumber + '' 
										   or Sub_Account_Agent_Legal_Name like '%' + @SALegalName + '' 
										   --or RequstedDate like '%' + @RequstedDate + '' 
										   or Sub_Account_Number like '%' + @SAnumber + '' 
										   or Sub_Account_Master_Account_Name like '%' + @MasterAccountName + '' 
										   or Case_Id like '%' +  CAST(@SACaseID AS NVARCHAR) + '%' 
										   or Sub_Account_Master_Account_TIN like '' + @MasterAccountTIN + '' 
	 end
	 if(@filter = 'ExactMatch')
	 begin
	     select * from CDDGSAGeneralInfo where Requested_By =  '' + @RequstedBy + ''  
		                                   or Request_Number = '' + @RequestNumber + '' 
										   or Sub_Account_Agent_Legal_Name = '' + @SALegalName + '' 
										   --or RequstedDate = '' + @RequstedDate + '' 
										   or Sub_Account_Number = '' + @SAnumber + '' 
										   or Sub_Account_Master_Account_Name = '' + @MasterAccountName + '' 
										   or Case_Id = '' +  CAST(@SACaseID AS NVARCHAR) + '%' 
										   or Sub_Account_Master_Account_TIN = '' + @MasterAccountTIN + '' 
	 end
END
GO
