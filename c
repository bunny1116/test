USE [CDDG]
GO
/****** Object:  Table [dbo].[CDDGAccess]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGAccess](
	[AccessID] [int] IDENTITY(1,1) NOT NULL,
	[Access] [varchar](30) NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGACCESS] PRIMARY KEY CLUSTERED 
(
	[AccessID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGActionLog]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGActionLog](
	[ActionLogID] [int] IDENTITY(1,1) NOT NULL,
	[Controller] [varchar](100) NULL,
	[Action] [varchar](100) NULL,
	[UpdatedBy] [varchar](25) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](25) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKActionLog] PRIMARY KEY CLUSTERED 
(
	[ActionLogID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGAttachment]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGAttachment](
	[AttachmentID] [int] IDENTITY(1,1) NOT NULL,
	[AttachmentType] [varchar](25) NULL,
	[Attachment] [varbinary](1) NULL,
	[PepId] [int] NOT NULL,
	[FileName] [varchar](255) NOT NULL,
	[FileStoragePath] [varchar](255) NOT NULL,
	[UpdatedBy] [varchar](255) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](255) NOT NULL,
	[CreatedTS] [datetime] NOT NULL,
	[EndDate] [datetime] NULL,
	[PepRequestStatusID] [int] NULL,
	[ChangeRequestID] [int] NULL,
 CONSTRAINT [XPKCDDGATTACHMENT] PRIMARY KEY CLUSTERED 
(
	[AttachmentID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGAttachmentHistory]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGAttachmentHistory](
	[AttachmentID] [int] IDENTITY(1,1) NOT NULL,
	[AttachmentType] [varchar](25) NULL,
	[Attachment] [varbinary](1) NULL,
	[UpdatedBy] [varchar](25) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](25) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[PEPPK] [int] NULL,
 CONSTRAINT [XPKCDDGAttachmentHistory] PRIMARY KEY CLUSTERED 
(
	[AttachmentID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGBookingOffice]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGBookingOffice](
	[OfficeID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [varchar](255) NULL,
	[CreatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedBy] [varchar](255) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
PRIMARY KEY CLUSTERED 
(
	[OfficeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGBSAApproval]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGBSAApproval](
	[BSAApprovalId] [int] IDENTITY(1,1) NOT NULL,
	[Status] [varchar](15) NULL,
	[CreatedBy] [varchar](10) NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGBSAApproval] PRIMARY KEY CLUSTERED 
(
	[BSAApprovalId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGChangeRequest]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGChangeRequest](
	[ChangeRequestId] [int] IDENTITY(1,1) NOT NULL,
	[PepId] [int] NULL,
	[UserId] [int] NULL,
	[AssignedUserId] [int] NULL,
	[CreatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[CountryId] [int] NULL,
	[PepLevelId] [int] NULL,
	[CustomerId] [int] NULL,
	[PepRequestStatusId] [int] NULL,
	[RequesterDeterminationComments] [varchar](max) NULL,
	[UpdateBy] [varchar](255) NULL,
	[UpdatedTS] [datetime] NULL,
	[InitialRequestDate] [datetime] NULL,
	[DeterminationUpdationDate] [datetime] NULL,
	[RequestorComments] [varchar](255) NULL,
	[HoganFlagDate] [datetime] NULL,
	[IsPep] [bit] NULL,
	[ReasonNotPepId] [int] NULL,
	[WFBranchId] [int] NULL,
	[BookingOfficeId] [int] NULL,
	[PepCancellationComments] [varchar](300) NULL,
	[PreviousPepRequestStatusid] [int] NULL,
	[PepTypeId] [int] NULL,
	[WCISNumber] [varchar](50) NULL,
	[ServiceRequestTypeId] [int] NULL,
	[CrNo] [int] NULL,
 CONSTRAINT [XPKCDDGChangeRequest] PRIMARY KEY CLUSTERED 
(
	[ChangeRequestId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGCountry]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGCountry](
	[CountryID] [int] IDENTITY(1,1) NOT NULL,
	[Country] [nvarchar](50) NULL,
	[UpdatedBY] [varchar](25) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](25) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[CountryRiskDesignationId] [int] NULL,
 CONSTRAINT [XPKCDDGCOUNTRY] PRIMARY KEY CLUSTERED 
(
	[CountryID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGCountryRiskDesignation]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGCountryRiskDesignation](
	[CountryRiskDesignationId] [int] IDENTITY(1,1) NOT NULL,
	[RiskDesignation] [varchar](25) NULL,
	[CreatedBy] [varchar](10) NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGCountryRiskDesignation] PRIMARY KEY CLUSTERED 
(
	[CountryRiskDesignationId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGCustomer]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGCustomer](
	[CustomerID] [int] IDENTITY(1,1) NOT NULL,
	[CustomerName] [varchar](255) NULL,
	[CustomerEmail] [varchar](255) NULL,
	[CustomerAddress] [varchar](255) NULL,
	[CustomerStatus] [int] NULL,
	[IsEntity] [bit] NULL,
	[EntityName] [varchar](255) NULL,
	[EntityFormationCountry] [int] NULL,
	[IndividualFirstName] [varchar](255) NULL,
	[IndividualLastName] [varchar](255) NULL,
	[IndividualMiddleName] [varchar](255) NULL,
	[IndividualLastName2] [varchar](255) NULL,
	[IndividualAKAName] [varchar](255) NULL,
	[IndividualDoB] [datetime] NULL,
	[IndividualCitizenshipCountry] [int] NULL,
	[EndDate] [datetime] NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](255) NULL,
	[UpdatedBy] [varchar](255) NULL,
	[CountryBSAApprovalId] [int] NULL,
 CONSTRAINT [XPKCDDGCUSTOMER] PRIMARY KEY CLUSTERED 
(
	[CustomerID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGCustomerCountryLob]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGCustomerCountryLob](
	[CustomerCountryLobId] [int] IDENTITY(1,1) NOT NULL,
	[CustomerId] [int] NOT NULL,
	[LobId] [int] NOT NULL,
	[CreatedBy] [varchar](255) NULL,
	[UpdatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGCustomerCountryLob] PRIMARY KEY CLUSTERED 
(
	[CustomerCountryLobId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGCustomerStatus]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGCustomerStatus](
	[StatusId] [int] NOT NULL,
	[Status] [varchar](100) NULL,
	[UpdatedBy] [varchar](255) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGCustomerStatus] PRIMARY KEY CLUSTERED 
(
	[StatusId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGDetermination]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGDetermination](
	[DeterminationID] [int] IDENTITY(1,1) NOT NULL,
	[Determination] [varchar](25) NULL,
	[UpdatedBy] [varchar](25) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](25) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGDETERMINATION] PRIMARY KEY CLUSTERED 
(
	[DeterminationID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGDetrequester]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGDetrequester](
	[DetId] [int] IDENTITY(1,1) NOT NULL,
	[DeterminationStatus] [varchar](25) NULL,
	[UpdateBy] [varchar](25) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](25) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGDETREQUESTER] PRIMARY KEY CLUSTERED 
(
	[DetId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGEcn]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGEcn](
	[EcnId] [int] IDENTITY(1,1) NOT NULL,
	[PepId] [int] NOT NULL,
	[Ecn] [varchar](255) NULL,
	[EcnSeqValNum] [varchar](25) NULL,
	[EcnSeqVal] [varchar](255) NULL,
	[UpdatedBy] [varchar](255) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBY] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[IsFlagged] [bit] NULL,
	[DateFlagged] [datetime] NULL,
	[PepRequestStatusID] [int] NULL,
	[ChangeRequestID] [int] NULL,
	[PrimaryEcnNotProvided] [bit] NOT NULL,
 CONSTRAINT [XPKCDDGECN] PRIMARY KEY CLUSTERED 
(
	[EcnId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGExceptions]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGExceptions](
	[exceptionID] [int] IDENTITY(1,1) NOT NULL,
	[applicationID] [int] NULL,
	[custExceptNum] [int] NULL,
	[category] [int] NULL,
	[custExceptMsg] [varchar](max) NULL,
	[custExceptMethod] [varchar](2000) NULL,
	[custExceptStackTrace] [varchar](5000) NULL,
	[innerExceptMsg] [varchar](1000) NULL,
	[innerExceptStackTrace] [varchar](5000) NULL,
	[exceptSource] [varchar](255) NULL,
	[exceptLineNum] [int] NULL,
	[userID] [varchar](25) NOT NULL,
	[insertDate] [datetime] NULL,
	[comments] [varchar](255) NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGExceptions] PRIMARY KEY CLUSTERED 
(
	[exceptionID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGGroup]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGGroup](
	[GroupID] [int] IDENTITY(1,1) NOT NULL,
	[GroupName] [varchar](50) NULL,
	[GroupDesc] [varchar](30) NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGGROUP] PRIMARY KEY CLUSTERED 
(
	[GroupID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGHoganPepFlagStatus]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGHoganPepFlagStatus](
	[PepFlagStatusId] [int] IDENTITY(1,1) NOT NULL,
	[PepFlagStatus] [varchar](50) NULL,
	[UpdatedBy] [varchar](25) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](25) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGHOGANPEPFLAGSTATUS] PRIMARY KEY CLUSTERED 
(
	[PepFlagStatusId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGHolidayList]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGHolidayList](
	[HolidayID] [int] IDENTITY(1,1) NOT NULL,
	[HolidayDate] [datetime] NULL,
	[HolidayDay] [varchar](20) NULL,
	[Reason] [varchar](255) NULL,
PRIMARY KEY CLUSTERED 
(
	[HolidayID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGLob]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGLob](
	[LobId] [int] IDENTITY(1,1) NOT NULL,
	[MajorLobId] [int] NULL,
	[LobName] [varchar](255) NULL,
	[UpdatedBy] [varchar](25) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](25) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGLOB] PRIMARY KEY CLUSTERED 
(
	[LobId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGLobPep]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGLobPep](
	[LobPepId] [int] IDENTITY(1,1) NOT NULL,
	[PepId] [int] NOT NULL,
	[LobId] [int] NOT NULL,
	[CreatedBy] [varchar](255) NULL,
	[UpdatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[PepRequestStatusID] [int] NULL,
	[ChangeRequestID] [int] NULL,
 CONSTRAINT [XPKCDDGLobPep] PRIMARY KEY CLUSTERED 
(
	[LobPepId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGMaintenanceWindow]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGMaintenanceWindow](
	[MaintenanceID] [int] IDENTITY(1,1) NOT NULL,
	[MaintenanceStartDateTS] [datetime] NOT NULL,
	[MaintenanceEndDateTS] [datetime] NOT NULL,
	[CreatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedBy] [varchar](255) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGMajorLob]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGMajorLob](
	[MajorLobId] [int] IDENTITY(1,1) NOT NULL,
	[MajorLOBName] [varchar](50) NULL,
	[UpdatedBy] [varchar](25) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](25) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGMAJORLOB] PRIMARY KEY CLUSTERED 
(
	[MajorLobId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGPep]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGPep](
	[PepId] [int] IDENTITY(1,1) NOT NULL,
	[CountryId] [int] NULL,
	[PepLevelId] [int] NULL,
	[PepRequestStatusId] [int] NULL,
	[InitialRequestDate] [datetime] NULL,
	[DeterminationUpdationDate] [datetime] NULL,
	[RequestorComments] [varchar](max) NULL,
	[HoganFlagDate] [datetime] NULL,
	[CreatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedBy] [varchar](255) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[CustomerId] [int] NULL,
	[IsPep] [bit] NULL,
	[ReasonNotPepId] [int] NULL,
	[WFBranchId] [int] NULL,
	[BookingOfficeId] [int] NULL,
	[PepCancellationComments] [varchar](300) NULL,
	[PreviousPepRequestStatusid] [int] NULL,
	[PepTypeId] [int] NULL,
	[WCISNumber] [varchar](50) NULL,
	[ServiceRequestTypeId] [int] NULL,
	[IsHoganFlagSet] [bit] NULL,
	[PepDeterminationComments] [varchar](max) NULL,
 CONSTRAINT [XPKCDDGPep] PRIMARY KEY CLUSTERED 
(
	[PepId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGPepHistory]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGPepHistory](
	[PepHistoryId] [int] IDENTITY(1,1) NOT NULL,
	[PepId] [int] NOT NULL,
	[CountryId] [int] NULL,
	[PepLevelId] [int] NULL,
	[PepRequestStatusId] [int] NULL,
	[InitialRequestDate] [datetime] NULL,
	[DeterminationUpdationDate] [datetime] NULL,
	[RequestorComments] [varchar](max) NULL,
	[PepDeterminationComments] [varchar](max) NULL,
	[HoganFlagDate] [datetime] NULL,
	[CreatedBy] [varchar](255) NOT NULL,
	[CreatedTS] [datetime] NOT NULL,
	[UpdatedBy] [varchar](255) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[CustomerId] [int] NULL,
	[IsPep] [bit] NULL,
	[ReasonNotPepId] [int] NULL,
	[WFBranchId] [int] NULL,
	[BookingOfficeId] [int] NULL,
	[PepCancellationComments] [varchar](300) NULL,
	[PreviousPepRequestStatusid] [int] NULL,
	[PepTypeId] [int] NULL,
	[WCISNumber] [varchar](50) NULL,
	[ServiceRequestTypeId] [int] NULL,
 CONSTRAINT [XPKCDDGPepHistory] PRIMARY KEY CLUSTERED 
(
	[PepHistoryId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGPepLevel]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGPepLevel](
	[PepLevelId] [int] IDENTITY(1,1) NOT NULL,
	[PepLevel] [varchar](18) NULL,
	[CreatedBy] [varchar](25) NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedBy] [varchar](25) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGPEPLEVEL] PRIMARY KEY CLUSTERED 
(
	[PepLevelId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGPepRequestAutoAssignment]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGPepRequestAutoAssignment](
	[AutoAssignmentId] [int] IDENTITY(1,1) NOT NULL,
	[UserId] [int] NULL,
	[IsAutoAssignmentEnabled] [bit] NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[AutoAssignmentBlackOutStartDate] [datetime] NULL,
	[AutoAssignmentBlackOutEndDate] [datetime] NULL,
	[AssignmentThresholdPercentage] [int] NULL,
	[CreatedBy] [varchar](255) NULL,
	[UpdatedBy] [varchar](255) NULL,
	[LastAutoAssignmentDate] [datetime] NULL,
	[TotalTeamAutoAssignmentEnabled] [bit] NULL,
 CONSTRAINT [XPKCDDGPepRequestAutoAssignment] PRIMARY KEY CLUSTERED 
(
	[AutoAssignmentId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGPEPRequestStatus]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGPEPRequestStatus](
	[PepRequestStatusID] [int] IDENTITY(1,1) NOT NULL,
	[StatusName] [varchar](100) NULL,
	[UpdatedBy] [varchar](100) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](100) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKPEPRequestStatus] PRIMARY KEY CLUSTERED 
(
	[PepRequestStatusID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGPepType]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGPepType](
	[PepTypeId] [int] IDENTITY(1,1) NOT NULL,
	[PepType] [varchar](25) NULL,
	[UpdatedBy] [varchar](255) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGPEPTYPE] PRIMARY KEY CLUSTERED 
(
	[PepTypeId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGPrimaryPep]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGPrimaryPep](
	[PrimaryPepId] [int] IDENTITY(1,1) NOT NULL,
	[PepId] [int] NULL,
	[FirstName] [varchar](255) NULL,
	[LastName] [varchar](255) NULL,
	[LastName2] [varchar](255) NULL,
	[MiddleName] [varchar](255) NULL,
	[AKAName] [varchar](255) NULL,
	[PrimaryPepPositionId] [int] NULL,
	[PrimaryPepAssociationId] [int] NULL,
	[PrimaryPepAssociatedCountryId] [int] NULL,
	[UpdatedBy] [varchar](100) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](100) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[PepRequestStatusID] [int] NULL,
	[ChangeRequestID] [int] NULL,
	[PrimaryPepCountryId] [int] NULL,
	[CountryBSAApprovalId] [int] NULL,
	[CountryLobDate] [datetime] NULL,
	[AssociatedCountryLobDate] [datetime] NULL,
	[AssociatedCountryBSAApprovalId] [int] NULL,
	[PrimaryPepPositionOpenField] [varchar](max) NULL,
	[UpdatedFields] [varchar](200) NULL,
	[PreviousPrimaryPepId] [int] NULL,
 CONSTRAINT [XPKCDDGPrimaryPep] PRIMARY KEY CLUSTERED 
(
	[PrimaryPepId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGPrimaryPepAssociatedCountryLob]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGPrimaryPepAssociatedCountryLob](
	[PrimaryPepLobId] [int] IDENTITY(1,1) NOT NULL,
	[PrimaryPepId] [int] NOT NULL,
	[LobId] [int] NOT NULL,
	[CreatedBy] [varchar](255) NULL,
	[UpdatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[UpdatedTS] [datetime] NULL,
 CONSTRAINT [XPKCDDGPrimaryPepAssociatedCountryLob] PRIMARY KEY CLUSTERED 
(
	[PrimaryPepLobId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGPrimaryPepAssociation]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGPrimaryPepAssociation](
	[AssociationId] [int] IDENTITY(1,1) NOT NULL,
	[Association] [varchar](100) NULL,
	[UpdatedBy] [varchar](100) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](100) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGPrimaryPepAssociation] PRIMARY KEY CLUSTERED 
(
	[AssociationId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGPrimaryPepAssociationOption]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGPrimaryPepAssociationOption](
	[AssociationOptionId] [int] IDENTITY(1,1) NOT NULL,
	[AssociationOption] [varchar](100) NULL,
	[AssociationId] [int] NOT NULL,
	[UpdatedBy] [varchar](25) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](25) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGPrimaryPepAssociationOption] PRIMARY KEY CLUSTERED 
(
	[AssociationOptionId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGPrimaryPepCountryLob]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGPrimaryPepCountryLob](
	[PrimaryPepLobId] [int] IDENTITY(1,1) NOT NULL,
	[PrimaryPepId] [int] NOT NULL,
	[LobId] [int] NOT NULL,
	[CreatedBy] [varchar](255) NULL,
	[UpdatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[UpdatedTS] [datetime] NULL,
 CONSTRAINT [XPKCDDGPrimaryPepLob] PRIMARY KEY CLUSTERED 
(
	[PrimaryPepLobId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGPrimaryPepPosition]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGPrimaryPepPosition](
	[PrimaryPepPositionId] [int] IDENTITY(1,1) NOT NULL,
	[PrimaryPepPositionName] [varchar](100) NULL,
	[UpdatedBy] [varchar](100) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](100) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGPrimaryPepPosition] PRIMARY KEY CLUSTERED 
(
	[PrimaryPepPositionId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGQuarter]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGQuarter](
	[QuarterID] [int] IDENTITY(1,1) NOT NULL,
	[Quarter] [char](18) NULL,
	[UpdatedBy] [varchar](25) NULL,
	[UdatedTS] [datetime] NULL,
	[CreatedByTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[CreatedBy] [varchar](25) NULL,
 CONSTRAINT [XPKCDDGQUARTER] PRIMARY KEY CLUSTERED 
(
	[QuarterID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGReasonNotPep]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGReasonNotPep](
	[ReasonID] [int] IDENTITY(1,1) NOT NULL,
	[Reason] [varchar](255) NULL,
	[CreatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedBy] [varchar](255) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
PRIMARY KEY CLUSTERED 
(
	[ReasonID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGReconsiderPep]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGReconsiderPep](
	[ReconsiderPepId] [int] IDENTITY(1,1) NOT NULL,
	[ReconsiderPepStatus] [varchar](255) NULL,
	[UpdatedBy] [varchar](25) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](25) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGRECONSIDERPEP] PRIMARY KEY CLUSTERED 
(
	[ReconsiderPepId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGRequestAssignment]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGRequestAssignment](
	[RequestAssignmentId] [int] IDENTITY(1,1) NOT NULL,
	[UserId] [int] NULL,
	[PepId] [int] NULL,
	[AssignedDate] [datetime] NULL,
	[ReassignedDate] [datetime] NULL,
	[Comments] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[PepRequestStatusID] [int] NULL,
	[ChangeRequestID] [int] NULL,
	[UpdatedBy] [varchar](255) NULL,
	[CreatedBy] [varchar](255) NULL,
 CONSTRAINT [XPKCDDGRequestAssignment] PRIMARY KEY CLUSTERED 
(
	[RequestAssignmentId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGRole]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGRole](
	[RoleID] [int] IDENTITY(1,1) NOT NULL,
	[RoleName] [varchar](75) NULL,
	[RoleDesc] [varchar](75) NULL,
	[DefaultLandingPage] [varchar](50) NULL,
	[DefaultLandingPageUrl] [varchar](100) NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGRole] PRIMARY KEY CLUSTERED 
(
	[RoleID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGRoleGroups]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGRoleGroups](
	[RoleGroupID] [int] IDENTITY(1,1) NOT NULL,
	[RoleID] [int] NULL,
	[GroupID] [int] NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGRoleGroups] PRIMARY KEY CLUSTERED 
(
	[RoleGroupID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY],
 CONSTRAINT [XURoleGroup] UNIQUE NONCLUSTERED 
(
	[RoleID] ASC,
	[GroupID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGRoleView]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGRoleView](
	[RoleViewID] [int] IDENTITY(1,1) NOT NULL,
	[RoleID] [int] NULL,
	[ViewID] [int] NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGROLEVIEW] PRIMARY KEY CLUSTERED 
(
	[RoleViewID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGRoleViewAccess]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGRoleViewAccess](
	[RoleViewAccessID] [int] IDENTITY(1,1) NOT NULL,
	[RoleViewID] [int] NULL,
	[AccessID] [int] NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGROLEVIEWACCESS] PRIMARY KEY CLUSTERED 
(
	[RoleViewAccessID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGServiceRequestType]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGServiceRequestType](
	[RequestID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [varchar](255) NULL,
	[CreatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedBy] [varchar](255) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
PRIMARY KEY CLUSTERED 
(
	[RequestID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGStatus]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGStatus](
	[StatusID] [int] IDENTITY(1,1) NOT NULL,
	[Status] [bit] NULL,
	[UpdatedBy] [varchar](100) NULL,
	[UpdatedTS] [datetime] NULL,
	[CreatedBy] [varchar](100) NULL,
	[CreatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGStatus] PRIMARY KEY CLUSTERED 
(
	[StatusID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGUser]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGUser](
	[UserID] [int] IDENTITY(1,1) NOT NULL,
	[LanID] [varchar](50) NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[LastLoggedTS] [datetime] NULL,
	[FirstName] [varchar](50) NULL,
	[LastName] [varchar](50) NULL,
	[Email] [varchar](50) NULL,
	[SIPAddress] [varchar](50) NULL,
	[Account] [varchar](50) NULL,
	[Aboutme] [varchar](400) NULL,
	[IsSiteAdmin] [bit] NULL,
	[Department] [varchar](50) NULL,
	[JobTitle] [varchar](50) NULL,
	[LegalName] [varchar](50) NULL,
	[PrimaryPhone] [varchar](15) NULL,
	[AlternatePhone] [varchar](15) NULL,
	[Fax] [varchar](15) NULL,
	[Mobile] [varchar](15) NULL,
	[Mac] [varchar](50) NULL,
	[Address] [varchar](50) NULL,
	[Floor] [varchar](50) NULL,
	[CityID] [int] NULL,
	[ExecOrg] [varchar](50) NULL,
	[Group] [varchar](50) NULL,
	[Region] [varchar](50) NULL,
	[Section] [varchar](50) NULL,
	[Area] [varchar](50) NULL,
	[AU] [varchar](10) NULL,
	[Zip] [varchar](10) NULL,
 CONSTRAINT [XPKCDDGUSER] PRIMARY KEY CLUSTERED 
(
	[UserID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGUserCity]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGUserCity](
	[CityID] [int] IDENTITY(1,1) NOT NULL,
	[CityName] [varchar](50) NULL,
	[StateID] [int] NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGUSERCITY] PRIMARY KEY CLUSTERED 
(
	[CityID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGUserCountry]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGUserCountry](
	[CountryID] [int] IDENTITY(1,1) NOT NULL,
	[CountryName] [varchar](50) NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGUSERCOUNTRY] PRIMARY KEY CLUSTERED 
(
	[CountryID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGUserRoles]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGUserRoles](
	[UserRoleID] [int] IDENTITY(1,1) NOT NULL,
	[UserID] [int] NULL,
	[RoleID] [int] NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGUSERROLES] PRIMARY KEY CLUSTERED 
(
	[UserRoleID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGUserState]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGUserState](
	[StateID] [int] IDENTITY(1,1) NOT NULL,
	[StateName] [varchar](50) NULL,
	[CountryID] [int] NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGUSERSTATE] PRIMARY KEY CLUSTERED 
(
	[StateID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGView]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGView](
	[ViewID] [int] IDENTITY(1,1) NOT NULL,
	[ViewName] [varchar](50) NULL,
	[ViewDesc] [varchar](100) NULL,
	[FileName] [varchar](50) NULL,
	[UrlPath] [varchar](100) NULL,
	[SortSeq] [smallint] NULL,
	[MenuClass] [varchar](50) NULL,
	[OnMouseOver] [varchar](50) NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKCDDGVIEW] PRIMARY KEY CLUSTERED 
(
	[ViewID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[CDDGWellsFargoBranch]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[CDDGWellsFargoBranch](
	[BranchID] [int] IDENTITY(1,1) NOT NULL,
	[BranchName] [varchar](255) NULL,
	[CreatedBy] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[UpdatedBy] [varchar](255) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
PRIMARY KEY CLUSTERED 
(
	[BranchID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[ChangedPEPFields]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[ChangedPEPFields](
	[ChangedFieldId] [int] IDENTITY(1,1) NOT NULL,
	[ChangeRequestId] [int] NULL,
	[PepId] [int] NULL,
	[ChangedFields] [varchar](max) NULL,
	[CreatedTS] [datetime] NULL,
	[DateofChange] [datetime] NULL,
PRIMARY KEY CLUSTERED 
(
	[ChangedFieldId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[EntityTypes]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[EntityTypes](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [varchar](50) NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKEntityTypes] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[ErrorLog]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[ErrorLog](
	[ErrorID] [int] IDENTITY(1,1) NOT NULL,
	[ErrorRow] [xml] NULL,
	[ErrorMessage] [varchar](1000) NULL,
	[ErrorIssuingPackage] [varchar](50) NULL,
	[ErrorSourceTable] [varchar](50) NULL,
	[ErrorDestinationTable] [varchar](50) NULL,
	[ErrorLoggingTime] [datetime] NULL
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].['Q4 2016 Country AML & TF Value$']    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].['Q4 2016 Country AML & TF Value$'](
	[COUNTRY] [nvarchar](255) NULL,
	[STATE DEPT# SOVEREIGNTY] [nvarchar](255) NULL,
	[HOGAN COUNTRY NAME] [nvarchar](255) NULL,
	[HOGAN/ISO ALPHA CODE] [nvarchar](255) NULL,
	[HOGAN/ISO NUMERIC CODE] [float] NULL,
	[TOTAL WEIGHTED SCORE] [float] NULL,
	[MANUAL OVERRIDE_(Sponsor of Terror, OFAC Sanctions, Non-cooperat] [nvarchar](255) NULL,
	[ANTIMONEYLAUNDERING] [nvarchar](255) NULL
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[StgApprovedSFCurrent]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[StgApprovedSFCurrent](
	[new_customer] [nvarchar](255) NULL,
	[ID] [nvarchar](255) NULL,
	[ecn] [nvarchar](255) NULL,
	[TAX_ID_NR] [nvarchar](255) NULL,
	[LINE_1_NM] [nvarchar](255) NULL,
	[LINE_2_NM] [nvarchar](255) NULL,
	[LINE_2_AD] [nvarchar](255) NULL,
	[CITY_NM] [nvarchar](255) NULL,
	[ST_PRVNC_CD] [nvarchar](255) NULL,
	[PSTL_CD] [nvarchar](255) NULL,
	[CUST_OPEN_DT] [nvarchar](255) NULL,
	[RISK_LEVEL] [nvarchar](255) NULL,
	[ECRR] [nvarchar](255) NULL,
	[WS_TPPP] [nvarchar](255) NULL,
	[CHECK_CASHER] [nvarchar](255) NULL,
	[COMMERCIAL] [nvarchar](255) NULL,
	[AGENT_FLAG] [nvarchar](255) NULL,
	[AGENTSUB_FLAG] [nvarchar](255) NULL,
	[PENDING_FLAG] [nvarchar](255) NULL,
	[DLR_FLAG] [nvarchar](255) NULL,
	[SWB_5_FLAG] [nvarchar](255) NULL,
	[SWB25_FLAG] [nvarchar](255) NULL,
	[HIA_FLAG] [nvarchar](255) NULL,
	[HIDTA_FLAG] [nvarchar](255) NULL,
	[HIFCA_FLAG] [nvarchar](255) NULL,
	[SOUTH_FLORIDA_FLAG] [nvarchar](255) NULL,
	[RDC_FLAG] [nvarchar](255) NULL,
	[CASH_VAULT] [nvarchar](255) NULL,
	[SAR_CNT] [nvarchar](255) NULL,
	[close_rsn_cde] [nvarchar](255) NULL,
	[new_acct] [nvarchar](255) NULL,
	[ACCT_CO_NR] [nvarchar](255) NULL,
	[ACCT_NR] [nvarchar](255) NULL,
	[ACCT_PD_CD] [nvarchar](255) NULL,
	[BMG_ACCT_NUM] [nvarchar](255) NULL,
	[PRDCT_DESC] [nvarchar](255) NULL,
	[SRC_ACCT_SUB_PD_CD] [nvarchar](255) NULL,
	[SUB_PRDCT_DESC_VRB] [nvarchar](255) NULL,
	[SUB_ACCOUNT] [nvarchar](255) NULL,
	[STORE_TEXT] [nvarchar](255) NULL,
	[MAST_ACCT_ID] [nvarchar](255) NULL,
	[ACCT_OPEN_DT] [nvarchar](255) NULL,
	[ACCT_CLOS_DT] [nvarchar](255) NULL,
	[AU] [nvarchar](255) NULL,
	[RAU] [nvarchar](255) NULL,
	[RABU_AU] [nvarchar](255) NULL,
	[AU_DIST_NAME] [nvarchar](255) NULL,
	[AU_DIV_NAME] [nvarchar](255) NULL,
	[AU_GRP_NAME] [nvarchar](255) NULL,
	[SUPER_RABU_NM] [nvarchar](255) NULL,
	[GRP_ORG_NM] [nvarchar](255) NULL,
	[CURR_BAL_AM] [float] NULL,
	[CURR_CLCT_BAL_AM] [float] NULL,
	[CURR_BAL_DT] [float] NULL,
	[AVG_DAILY_BAL] [float] NULL,
	[AVG_DAILY_COLL_BAL] [float] NULL,
	[CASH_IN] [float] NULL,
	[CASH_IN_CNT] [float] NULL,
	[CASH_IN_AVG] [float] NULL,
	[CASH_OUT] [float] NULL,
	[CASH_OUT_CNT] [float] NULL,
	[CASH_OUT_AVG] [float] NULL,
	[CHECK_IN] [float] NULL,
	[CHECK_IN_CNT] [float] NULL,
	[CHECK_IN_AVG] [float] NULL,
	[CHECK_OUT] [float] NULL,
	[CHECK_OUT_CNT] [float] NULL,
	[CHECK_OUT_AVG] [float] NULL,
	[ACH_IN] [float] NULL,
	[ACH_IN_CNT] [float] NULL,
	[ACH_IN_AVG] [float] NULL,
	[ACH_OUT] [float] NULL,
	[ACH_OUT_CNT] [float] NULL,
	[ACH_OUT_AVG] [float] NULL,
	[WIRES_IN] [float] NULL,
	[WIRES_IN_CNT] [float] NULL,
	[WIRES_IN_AVG] [float] NULL,
	[WIRES_OUT] [float] NULL,
	[WIRES_OUT_CNT] [float] NULL,
	[WIRES_OUT_AVG] [float] NULL,
	[INCOMING_TRAN_TOTAL_AMT] [float] NULL,
	[INCOMING_TRAN_TOTAL_CNT] [float] NULL,
	[OUTGOING_TRAN_TOTAL_AMT] [float] NULL,
	[OUTGOING_TRAN_TOTAL_CNT] [float] NULL,
	[OTHER_CREDIT] [float] NULL,
	[OTHER_CREDIT_CNT] [float] NULL,
	[OTHER_CREDIT_AVG] [float] NULL,
	[OTHER_DEBIT] [float] NULL,
	[OTHER_DEBIT_CNT] [float] NULL,
	[OTHER_DEBIT_AVG] [float] NULL,
	[CASH_VAULT_OUT] [float] NULL,
	[CASH_VAULT_OUT_CNT] [float] NULL,
	[CASH_VAULT_OUT_AVG] [float] NULL,
	[CASH_VAULT_IN] [float] NULL,
	[CASH_VAULT_IN_CNT] [float] NULL,
	[CV_DEPOSIT_AVG] [float] NULL,
	[RDC] [float] NULL,
	[RDC_CNT] [float] NULL,
	[RDC_AVG] [float] NULL,
	[GOVTCHEK] [float] NULL,
	[GOVTCHEK_CNT] [float] NULL,
	[GOVTCHEK_AVG] [float] NULL,
	[DOM_WIRE_IN] [float] NULL,
	[DOM_WIRE_IN_CNT] [float] NULL,
	[DOM_WIRE_IN_AVG] [float] NULL,
	[DOM_WIRE_OUT] [float] NULL,
	[DOM_WIRE_OUT_CNT] [float] NULL,
	[DOM_WIRE_OUT_AVG] [float] NULL,
	[INTL_WIRE_IN] [float] NULL,
	[INTL_WIRE_IN_CNT] [float] NULL,
	[INTL_WIRE_IN_AVG] [float] NULL,
	[INTL_WIRE_OUT] [float] NULL,
	[INTL_WIRE_OUT_CNT] [float] NULL,
	[INTL_WIRE_OUT_AVG] [float] NULL,
	[ACH_PRINCIPAL] [float] NULL,
	[ACH_PRINCIPAL_CNT] [float] NULL,
	[ACH_PRINCIPAL_AVG] [float] NULL,
	[ACH_RETURN] [float] NULL,
	[ACH_RETURN_CNT] [float] NULL,
	[ACH_RETURN_AVG] [float] NULL,
	[ACH_WF_ORIG_IN_AMT] [float] NULL,
	[ACH_WF_ORIG_IN_CNT] [float] NULL,
	[ACH_WF_ORIG_IN_AVG] [float] NULL,
	[ACH_WF_ORIG_OUT_AMT] [float] NULL,
	[ACH_WF_ORIG_OUT_CNT] [float] NULL,
	[ACH_WF_ORIG_OUT_AVG] [float] NULL,
	[RETURN_ITEM] [float] NULL,
	[RETURN_ITEM_CNT] [float] NULL,
	[RETURN_ITEM_AVG] [float] NULL,
	[FEE_RVRSL] [float] NULL,
	[FEE_RVRSL_CNT] [float] NULL,
	[FEE_RVRSL_AVG] [float] NULL,
	[FEE] [float] NULL,
	[FEE_CNT] [float] NULL,
	[FEE_AVG] [float] NULL,
	[FX_IN] [float] NULL,
	[FX_IN_CNT] [float] NULL,
	[FX_IN_AVG] [float] NULL,
	[FX_OUT] [float] NULL,
	[FX_OUT_CNT] [float] NULL,
	[FX_OUT_AVG] [float] NULL,
	[RABU_NM] [nvarchar](255) NULL
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[sysssislog]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[sysssislog](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[event] [sysname] NOT NULL,
	[computer] [nvarchar](128) NOT NULL,
	[operator] [nvarchar](128) NOT NULL,
	[source] [nvarchar](1024) NOT NULL,
	[sourceid] [uniqueidentifier] NOT NULL,
	[executionid] [uniqueidentifier] NOT NULL,
	[starttime] [datetime] NOT NULL,
	[endtime] [datetime] NOT NULL,
	[datacode] [int] NOT NULL,
	[databytes] [image] NULL,
	[message] [nvarchar](2048) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[T_Country]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[T_Country](
	[ID] [int] NULL,
	[Associated Country] [varchar](255) NULL,
	[Content Type] [varchar](255) NULL,
	[Workflow Instance ID] [varchar](255) NULL,
	[File Type] [varchar](255) NULL,
	[Modified] [datetime] NULL,
	[Created] [datetime] NULL,
	[Created By] [int] NULL,
	[CreatedBy] [varchar](30) NULL,
	[Modified By] [int] NULL,
	[ModifiedBy] [varchar](30) NULL,
	[URL Path] [varchar](255) NULL,
	[Path] [varchar](255) NULL,
	[Item Type] [varchar](255) NULL,
	[Encoded Absolute URL] [varchar](255) NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[T_ECN]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[T_ECN](
	[Modified] [datetime] NULL,
	[Created] [datetime] NULL,
	[CreatedBy] [varchar](30) NULL,
	[ModifiedBy] [varchar](30) NULL,
	[ECNID] [int] NULL,
	[DETID] [varchar](255) NULL,
	[ECN] [varchar](255) NULL,
	[FLAG_DATE] [datetime] NULL,
	[PEPFlag] [bit] NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[T_LOB]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[T_LOB](
	[ID] [int] NULL,
	[Content Type] [varchar](255) NULL,
	[Workflow Instance ID] [varchar](255) NULL,
	[File Type] [varchar](255) NULL,
	[Modified] [datetime] NULL,
	[Created] [datetime] NULL,
	[Created By] [int] NULL,
	[CreatedBy] [varchar](30) NULL,
	[Modified By] [int] NULL,
	[ModifiedBy] [varchar](30) NULL,
	[URL Path] [varchar](255) NULL,
	[Path] [varchar](255) NULL,
	[Item Type] [varchar](255) NULL,
	[Encoded Absolute URL] [varchar](255) NULL,
	[LOB] [varchar](255) NULL,
	[MAJOR_LOB] [varchar](255) NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[T_PEP]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[T_PEP](
	[ID] [int] NULL,
	[Associated Country] [varchar](255) NULL,
	[Content Type] [varchar](255) NULL,
	[Workflow Instance ID] [varchar](255) NULL,
	[File Type] [varchar](255) NULL,
	[Modified] [datetime] NULL,
	[Created] [datetime] NULL,
	[Created By] [int] NULL,
	[CreatedBy] [varchar](30) NULL,
	[Modified By] [int] NULL,
	[ModifiedBy] [varchar](30) NULL,
	[URL Path] [varchar](255) NULL,
	[Path] [varchar](255) NULL,
	[Item Type] [varchar](255) NULL,
	[Encoded Absolute URL] [varchar](255) NULL,
	[Customer Identified in PEP determination Form] [varchar](255) NULL,
	[ECN] [varchar](255) NULL,
	[ECN2] [varchar](255) NULL,
	[ECN3] [varchar](255) NULL,
	[ECN4] [varchar](255) NULL,
	[ECN5] [varchar](20) NULL,
	[ECN6] [varchar](20) NULL,
	[_ID] [float] NULL,
	[determination #] [float] NULL,
	[Primary PEP association] [varchar](255) NULL,
	[Primary PEP Position] [varchar](max) NULL,
	[MajorLOB] [varchar](255) NULL,
	[LOB] [varchar](255) NULL,
	[MAJORLOB2] [varchar](255) NULL,
	[LOB2] [varchar](255) NULL,
	[Major LOB3] [varchar](255) NULL,
	[LOB3] [varchar](255) NULL,
	[Major LOB4] [varchar](50) NULL,
	[LOB4] [varchar](50) NULL,
	[Requestor] [varchar](255) NULL,
	[Credit Investigations Y/N] [varchar](255) NULL,
	[Reconsideration/de-PEP] [varchar](255) NULL,
	[Credit Investigation Analyst] [varchar](255) NULL,
	[Initial request date] [datetime] NULL,
	[Final Response Date] [datetime] NULL,
	[Quarter] [varchar](255) NULL,
	[Determination] [varchar](255) NULL,
	[PEP Type (Customer)] [varchar](255) NULL,
	[Reason not a PEP] [nvarchar](max) NULL,
	[PEP Level] [varchar](255) NULL,
	[Additional Info needed?] [varchar](255) NULL,
	[Could the dermination been made by requestor?] [varchar](255) NULL,
	[Observation] [varchar](255) NULL,
	[PEP Flag Set in Hogan?] [varchar](255) NULL,
	[Additional comments] [varchar](255) NULL,
	[Requstor_Email] [varchar](255) NULL,
	[RequestorDetermineComments] [varchar](max) NULL,
	[FlagDate] [datetime] NULL,
	[CitizenshipCountry] [varchar](255) NULL,
	[HowAssociated] [varchar](255) NULL,
	[PEPAlertConfirmed] [varchar](max) NULL,
	[LOBApprovalReceived] [varchar](255) NULL,
	[DateApprovalReceived] [datetime] NULL,
	[ECN_NOTES] [varchar](255) NULL,
	[UploadFileDate] [datetime] NULL,
	[LOB_Reported] [varchar](max) NULL
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[T_Quater]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[T_Quater](
	[Content Type] [varchar](255) NULL,
	[Workflow Instance ID] [varchar](255) NULL,
	[File Type] [varchar](255) NULL,
	[Modified] [datetime] NULL,
	[Created] [datetime] NULL,
	[Created By] [int] NULL,
	[Modified By] [int] NULL,
	[ModifiedBy] [varchar](30) NULL,
	[URL Path] [varchar](255) NULL,
	[Path] [varchar](255) NULL,
	[Item Type] [varchar](255) NULL,
	[Encoded Absolute URL] [varchar](255) NULL,
	[QID] [int] NULL,
	[Quarter] [varchar](255) NULL,
	[_ID] [float] NULL,
	[CrreatedBy] [varchar](30) NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[T_UserInformationList]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[T_UserInformationList](
	[ID] [int] NULL,
	[Content Type] [varchar](255) NULL,
	[Workflow Instance ID] [varchar](255) NULL,
	[File Type] [varchar](255) NULL,
	[Modified] [datetime] NULL,
	[Created] [datetime] NULL,
	[Created By] [int] NULL,
	[Modified By] [int] NULL,
	[URL Path] [varchar](255) NULL,
	[Path] [varchar](255) NULL,
	[Item Type] [varchar](255) NULL,
	[Encoded Absolute URL] [varchar](255) NULL,
	[Name] [varchar](255) NULL,
	[Account] [varchar](255) NULL,
	[Email] [varchar](255) NULL,
	[About me] [varchar](max) NULL,
	[SIP Address] [varchar](255) NULL,
	[Is Site Admin] [bit] NULL,
	[Deleted] [bit] NULL,
	[Picture] [varchar](max) NULL,
	[Department] [varchar](255) NULL,
	[Job Title] [varchar](255) NULL,
	[First name] [varchar](255) NULL,
	[Last name] [varchar](255) NULL,
	[Responsibilities] [varchar](max) NULL,
	[Legal Name] [varchar](max) NULL,
	[Primary Phone] [varchar](255) NULL,
	[Alternate Phone] [varchar](255) NULL,
	[Pager] [varchar](255) NULL,
	[Fax] [varchar](255) NULL,
	[Mobile] [varchar](255) NULL,
	[MAC] [varchar](255) NULL,
	[Address] [varchar](255) NULL,
	[Floor] [varchar](255) NULL,
	[City] [varchar](255) NULL,
	[State] [varchar](255) NULL,
	[Zip] [varchar](255) NULL,
	[Country] [varchar](255) NULL,
	[Company] [varchar](255) NULL,
	[Exec Org] [varchar](255) NULL,
	[Org] [varchar](255) NULL,
	[Group] [varchar](255) NULL,
	[Region] [varchar](255) NULL,
	[Section] [varchar](255) NULL,
	[Area] [varchar](255) NULL,
	[AU] [varchar](255) NULL,
	[FirstLastName] [varchar](255) NULL,
	[Office] [varchar](255) NULL,
	[User name] [varchar](255) NULL,
	[Web site] [varchar](max) NULL,
	[Attachments] [varchar](max) NULL
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[TableChild]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[TableChild](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[PID] [int] NULL,
	[Name] [varchar](max) NULL,
PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[TableParent]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[TableParent](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [varchar](max) NULL,
PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[TableParentPrimary]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[TableParentPrimary](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[PID] [int] NULL,
	[Child] [int] NULL,
	[Name] [varchar](max) NULL,
PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[testsCR]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[testsCR](
	[testcrid] [int] IDENTITY(20000,1) NOT NULL,
	[testname] [varchar](10) NULL,
PRIMARY KEY CLUSTERED 
(
	[testcrid] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[WatchListDetail]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[WatchListDetail](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[WLID] [int] NULL,
	[EntityTypeID] [int] NULL,
	[FirstName] [varchar](100) NULL,
	[LastName] [varchar](100) NULL,
	[MiddleName] [varchar](100) NULL,
	[Title] [varchar](255) NULL,
	[Reason] [varchar](500) NULL,
	[Comment] [varchar](500) NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKWatchListDetail] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[WatchListDetailAddresses]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[WatchListDetailAddresses](
	[AddressID] [int] IDENTITY(1,1) NOT NULL,
	[WLID] [int] NULL,
	[WLDetailID] [int] NULL,
	[Address] [varchar](500) NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKWatchListDetailAddresses] PRIMARY KEY CLUSTERED 
(
	[AddressID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[WatchListDetailAKAs]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[WatchListDetailAKAs](
	[AKAID] [int] IDENTITY(1,1) NOT NULL,
	[WLID] [int] NULL,
	[WLDetailID] [int] NULL,
	[AKA] [varchar](500) NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKWatchListDetailAKAs] PRIMARY KEY CLUSTERED 
(
	[AKAID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[WatchLists]    Script Date: 7/1/2017 11:12:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[WatchLists](
	[WLID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [varchar](50) NULL,
	[Description] [varchar](255) NULL,
	[CreatedTS] [datetime] NULL,
	[CreatedBy] [varchar](10) NULL,
	[UpdatedBy] [varchar](10) NULL,
	[UpdatedTS] [datetime] NULL,
	[EndDate] [datetime] NULL,
 CONSTRAINT [XPKWatchLists] PRIMARY KEY CLUSTERED 
(
	[WLID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
ALTER TABLE [dbo].[CDDGEcn] ADD  DEFAULT ('0') FOR [PrimaryEcnNotProvided]
GO
ALTER TABLE [dbo].[CDDGPepRequestAutoAssignment] ADD  CONSTRAINT [IsAutoAssignmentEnabledDefault]  DEFAULT ((1)) FOR [IsAutoAssignmentEnabled]
GO
ALTER TABLE [dbo].[CDDGPepRequestAutoAssignment] ADD  DEFAULT ((0)) FOR [AssignmentThresholdPercentage]
GO
ALTER TABLE [dbo].[CDDGAttachment]  WITH CHECK ADD  CONSTRAINT [CDDGChangeRequest_CDDGAttachment_FK] FOREIGN KEY([ChangeRequestID])
REFERENCES [dbo].[CDDGChangeRequest] ([ChangeRequestId])
GO
ALTER TABLE [dbo].[CDDGAttachment] CHECK CONSTRAINT [CDDGChangeRequest_CDDGAttachment_FK]
GO
ALTER TABLE [dbo].[CDDGAttachment]  WITH CHECK ADD  CONSTRAINT [CDDGPEP_CDDGATTACHMENT_FK] FOREIGN KEY([PepId])
REFERENCES [dbo].[CDDGPep] ([PepId])
GO
ALTER TABLE [dbo].[CDDGAttachment] CHECK CONSTRAINT [CDDGPEP_CDDGATTACHMENT_FK]
GO
ALTER TABLE [dbo].[CDDGAttachment]  WITH CHECK ADD  CONSTRAINT [CDDGPEP_CDDGPEPRequestStatus_FK] FOREIGN KEY([PepRequestStatusID])
REFERENCES [dbo].[CDDGPEPRequestStatus] ([PepRequestStatusID])
GO
ALTER TABLE [dbo].[CDDGAttachment] CHECK CONSTRAINT [CDDGPEP_CDDGPEPRequestStatus_FK]
GO
ALTER TABLE [dbo].[CDDGChangeRequest]  WITH CHECK ADD  CONSTRAINT [CDDGBookingOffice_CDDGChangeRequest_FK] FOREIGN KEY([BookingOfficeId])
REFERENCES [dbo].[CDDGBookingOffice] ([OfficeID])
GO
ALTER TABLE [dbo].[CDDGChangeRequest] CHECK CONSTRAINT [CDDGBookingOffice_CDDGChangeRequest_FK]
GO
ALTER TABLE [dbo].[CDDGChangeRequest]  WITH CHECK ADD  CONSTRAINT [CDDGCountry_CDDGChangeRequest_FK] FOREIGN KEY([CountryId])
REFERENCES [dbo].[CDDGCountry] ([CountryID])
GO
ALTER TABLE [dbo].[CDDGChangeRequest] CHECK CONSTRAINT [CDDGCountry_CDDGChangeRequest_FK]
GO
ALTER TABLE [dbo].[CDDGChangeRequest]  WITH CHECK ADD  CONSTRAINT [CDDGCountryRiskDesignation_CDDGCustomer_FK] FOREIGN KEY([CustomerId])
REFERENCES [dbo].[CDDGCustomer] ([CustomerID])
GO
ALTER TABLE [dbo].[CDDGChangeRequest] CHECK CONSTRAINT [CDDGCountryRiskDesignation_CDDGCustomer_FK]
GO
ALTER TABLE [dbo].[CDDGChangeRequest]  WITH CHECK ADD  CONSTRAINT [CDDGCountryRiskDesignation_CDDGPepLevel_FK] FOREIGN KEY([PepLevelId])
REFERENCES [dbo].[CDDGPepLevel] ([PepLevelId])
GO
ALTER TABLE [dbo].[CDDGChangeRequest] CHECK CONSTRAINT [CDDGCountryRiskDesignation_CDDGPepLevel_FK]
GO
ALTER TABLE [dbo].[CDDGChangeRequest]  WITH CHECK ADD  CONSTRAINT [CDDGPEPRequestStatus_CDDGChangeRequest_FK] FOREIGN KEY([PepRequestStatusId])
REFERENCES [dbo].[CDDGPEPRequestStatus] ([PepRequestStatusID])
GO
ALTER TABLE [dbo].[CDDGChangeRequest] CHECK CONSTRAINT [CDDGPEPRequestStatus_CDDGChangeRequest_FK]
GO
ALTER TABLE [dbo].[CDDGChangeRequest]  WITH CHECK ADD  CONSTRAINT [CDDGPEPTYPE_cddgchangerequest_FK] FOREIGN KEY([PepTypeId])
REFERENCES [dbo].[CDDGPepType] ([PepTypeId])
GO
ALTER TABLE [dbo].[CDDGChangeRequest] CHECK CONSTRAINT [CDDGPEPTYPE_cddgchangerequest_FK]
GO
ALTER TABLE [dbo].[CDDGChangeRequest]  WITH CHECK ADD  CONSTRAINT [CDDGReasonNotPep_CDDGChangeRequest_FK] FOREIGN KEY([ReasonNotPepId])
REFERENCES [dbo].[CDDGReasonNotPep] ([ReasonID])
GO
ALTER TABLE [dbo].[CDDGChangeRequest] CHECK CONSTRAINT [CDDGReasonNotPep_CDDGChangeRequest_FK]
GO
ALTER TABLE [dbo].[CDDGChangeRequest]  WITH CHECK ADD  CONSTRAINT [CDDGServiceRequestType_cddgchangerequest_FK] FOREIGN KEY([ServiceRequestTypeId])
REFERENCES [dbo].[CDDGServiceRequestType] ([RequestID])
GO
ALTER TABLE [dbo].[CDDGChangeRequest] CHECK CONSTRAINT [CDDGServiceRequestType_cddgchangerequest_FK]
GO
ALTER TABLE [dbo].[CDDGChangeRequest]  WITH CHECK ADD  CONSTRAINT [CDDGUser_CDDGChangeRequest_FK] FOREIGN KEY([UserId])
REFERENCES [dbo].[CDDGUser] ([UserID])
GO
ALTER TABLE [dbo].[CDDGChangeRequest] CHECK CONSTRAINT [CDDGUser_CDDGChangeRequest_FK]
GO
ALTER TABLE [dbo].[CDDGChangeRequest]  WITH CHECK ADD  CONSTRAINT [CDDGWellsFargoBranch_CDDGChangeRequest_FK] FOREIGN KEY([WFBranchId])
REFERENCES [dbo].[CDDGWellsFargoBranch] ([BranchID])
GO
ALTER TABLE [dbo].[CDDGChangeRequest] CHECK CONSTRAINT [CDDGWellsFargoBranch_CDDGChangeRequest_FK]
GO
ALTER TABLE [dbo].[CDDGCountry]  WITH CHECK ADD  CONSTRAINT [CDDGCOUNTRYRISKDESIGNATION_CDDGCOUNTRY_FK] FOREIGN KEY([CountryRiskDesignationId])
REFERENCES [dbo].[CDDGCountryRiskDesignation] ([CountryRiskDesignationId])
GO
ALTER TABLE [dbo].[CDDGCountry] CHECK CONSTRAINT [CDDGCOUNTRYRISKDESIGNATION_CDDGCOUNTRY_FK]
GO
ALTER TABLE [dbo].[CDDGCustomer]  WITH CHECK ADD  CONSTRAINT [CDDGBSAApproval_CDDGCustomer_FK] FOREIGN KEY([CountryBSAApprovalId])
REFERENCES [dbo].[CDDGBSAApproval] ([BSAApprovalId])
GO
ALTER TABLE [dbo].[CDDGCustomer] CHECK CONSTRAINT [CDDGBSAApproval_CDDGCustomer_FK]
GO
ALTER TABLE [dbo].[CDDGCustomer]  WITH CHECK ADD  CONSTRAINT [CDDGCountry_CDDGCustomer_FK] FOREIGN KEY([EntityFormationCountry])
REFERENCES [dbo].[CDDGCountry] ([CountryID])
GO
ALTER TABLE [dbo].[CDDGCustomer] CHECK CONSTRAINT [CDDGCountry_CDDGCustomer_FK]
GO
ALTER TABLE [dbo].[CDDGCustomer]  WITH CHECK ADD  CONSTRAINT [CDDGCountry_CDDGCustomer_FK2] FOREIGN KEY([IndividualCitizenshipCountry])
REFERENCES [dbo].[CDDGCountry] ([CountryID])
GO
ALTER TABLE [dbo].[CDDGCustomer] CHECK CONSTRAINT [CDDGCountry_CDDGCustomer_FK2]
GO
ALTER TABLE [dbo].[CDDGCustomer]  WITH CHECK ADD  CONSTRAINT [CDDGCustomerStatus_CDDGCustomer_FK] FOREIGN KEY([CustomerStatus])
REFERENCES [dbo].[CDDGCustomerStatus] ([StatusId])
GO
ALTER TABLE [dbo].[CDDGCustomer] CHECK CONSTRAINT [CDDGCustomerStatus_CDDGCustomer_FK]
GO
ALTER TABLE [dbo].[CDDGCustomerCountryLob]  WITH CHECK ADD  CONSTRAINT [CDDGCUSTOMER_CDDGCUSTOMERCOUNTRYLOB_FK] FOREIGN KEY([CustomerId])
REFERENCES [dbo].[CDDGCustomer] ([CustomerID])
GO
ALTER TABLE [dbo].[CDDGCustomerCountryLob] CHECK CONSTRAINT [CDDGCUSTOMER_CDDGCUSTOMERCOUNTRYLOB_FK]
GO
ALTER TABLE [dbo].[CDDGCustomerCountryLob]  WITH CHECK ADD  CONSTRAINT [CDDGLOB_CDDGCUSTOMERCOUNTRYLOB_FK] FOREIGN KEY([LobId])
REFERENCES [dbo].[CDDGLob] ([LobId])
GO
ALTER TABLE [dbo].[CDDGCustomerCountryLob] CHECK CONSTRAINT [CDDGLOB_CDDGCUSTOMERCOUNTRYLOB_FK]
GO
ALTER TABLE [dbo].[CDDGEcn]  WITH CHECK ADD  CONSTRAINT [CDDGChangeRequest_CDDGEcn_FK] FOREIGN KEY([ChangeRequestID])
REFERENCES [dbo].[CDDGChangeRequest] ([ChangeRequestId])
GO
ALTER TABLE [dbo].[CDDGEcn] CHECK CONSTRAINT [CDDGChangeRequest_CDDGEcn_FK]
GO
ALTER TABLE [dbo].[CDDGEcn]  WITH CHECK ADD  CONSTRAINT [CDDGPEP_CDDGECN_FK] FOREIGN KEY([PepId])
REFERENCES [dbo].[CDDGPep] ([PepId])
GO
ALTER TABLE [dbo].[CDDGEcn] CHECK CONSTRAINT [CDDGPEP_CDDGECN_FK]
GO
ALTER TABLE [dbo].[CDDGEcn]  WITH CHECK ADD  CONSTRAINT [CDDGPEP_CDDGECN_FK1] FOREIGN KEY([PepRequestStatusID])
REFERENCES [dbo].[CDDGPEPRequestStatus] ([PepRequestStatusID])
GO
ALTER TABLE [dbo].[CDDGEcn] CHECK CONSTRAINT [CDDGPEP_CDDGECN_FK1]
GO
ALTER TABLE [dbo].[CDDGLob]  WITH NOCHECK ADD  CONSTRAINT [CDDGMajorLob_CDDGLob_FK] FOREIGN KEY([MajorLobId])
REFERENCES [dbo].[CDDGMajorLob] ([MajorLobId])
GO
ALTER TABLE [dbo].[CDDGLob] CHECK CONSTRAINT [CDDGMajorLob_CDDGLob_FK]
GO
ALTER TABLE [dbo].[CDDGLobPep]  WITH CHECK ADD  CONSTRAINT [CDDGChangeRequest_CDDGLOBPEP_FK] FOREIGN KEY([ChangeRequestID])
REFERENCES [dbo].[CDDGChangeRequest] ([ChangeRequestId])
GO
ALTER TABLE [dbo].[CDDGLobPep] CHECK CONSTRAINT [CDDGChangeRequest_CDDGLOBPEP_FK]
GO
ALTER TABLE [dbo].[CDDGLobPep]  WITH CHECK ADD  CONSTRAINT [CDDGLOB_CDDGLOBPEP_FK] FOREIGN KEY([LobId])
REFERENCES [dbo].[CDDGLob] ([LobId])
GO
ALTER TABLE [dbo].[CDDGLobPep] CHECK CONSTRAINT [CDDGLOB_CDDGLOBPEP_FK]
GO
ALTER TABLE [dbo].[CDDGLobPep]  WITH CHECK ADD  CONSTRAINT [CDDGLOB_CDDGLOBPEP_FK1] FOREIGN KEY([PepRequestStatusID])
REFERENCES [dbo].[CDDGPEPRequestStatus] ([PepRequestStatusID])
GO
ALTER TABLE [dbo].[CDDGLobPep] CHECK CONSTRAINT [CDDGLOB_CDDGLOBPEP_FK1]
GO
ALTER TABLE [dbo].[CDDGLobPep]  WITH CHECK ADD  CONSTRAINT [CDDGPEP_CDDGLOBPEP_FK] FOREIGN KEY([PepId])
REFERENCES [dbo].[CDDGPep] ([PepId])
GO
ALTER TABLE [dbo].[CDDGLobPep] CHECK CONSTRAINT [CDDGPEP_CDDGLOBPEP_FK]
GO
ALTER TABLE [dbo].[CDDGPep]  WITH CHECK ADD  CONSTRAINT [CDDGBookingOffice_CDDGPEP_FK] FOREIGN KEY([BookingOfficeId])
REFERENCES [dbo].[CDDGBookingOffice] ([OfficeID])
GO
ALTER TABLE [dbo].[CDDGPep] CHECK CONSTRAINT [CDDGBookingOffice_CDDGPEP_FK]
GO
ALTER TABLE [dbo].[CDDGPep]  WITH CHECK ADD  CONSTRAINT [CDDGCOUNTRY_CDDGPEP_FK] FOREIGN KEY([CountryId])
REFERENCES [dbo].[CDDGCountry] ([CountryID])
GO
ALTER TABLE [dbo].[CDDGPep] CHECK CONSTRAINT [CDDGCOUNTRY_CDDGPEP_FK]
GO
ALTER TABLE [dbo].[CDDGPep]  WITH CHECK ADD  CONSTRAINT [cddgcustomer_cddgpep_fk] FOREIGN KEY([CustomerId])
REFERENCES [dbo].[CDDGCustomer] ([CustomerID])
GO
ALTER TABLE [dbo].[CDDGPep] CHECK CONSTRAINT [cddgcustomer_cddgpep_fk]
GO
ALTER TABLE [dbo].[CDDGPep]  WITH CHECK ADD  CONSTRAINT [CDDGPEPLEVEL_CDDGPEP_FK] FOREIGN KEY([PepLevelId])
REFERENCES [dbo].[CDDGPepLevel] ([PepLevelId])
GO
ALTER TABLE [dbo].[CDDGPep] CHECK CONSTRAINT [CDDGPEPLEVEL_CDDGPEP_FK]
GO
ALTER TABLE [dbo].[CDDGPep]  WITH CHECK ADD  CONSTRAINT [CDDGPEPRequestStatus_CDDGPEP_FK] FOREIGN KEY([PepRequestStatusId])
REFERENCES [dbo].[CDDGPEPRequestStatus] ([PepRequestStatusID])
GO
ALTER TABLE [dbo].[CDDGPep] CHECK CONSTRAINT [CDDGPEPRequestStatus_CDDGPEP_FK]
GO
ALTER TABLE [dbo].[CDDGPep]  WITH CHECK ADD  CONSTRAINT [CDDGPepType_CDDGPEP_FK] FOREIGN KEY([PepTypeId])
REFERENCES [dbo].[CDDGPepType] ([PepTypeId])
GO
ALTER TABLE [dbo].[CDDGPep] CHECK CONSTRAINT [CDDGPepType_CDDGPEP_FK]
GO
ALTER TABLE [dbo].[CDDGPep]  WITH CHECK ADD  CONSTRAINT [CDDGReasonNotPep_CDDGPEP_FK] FOREIGN KEY([ReasonNotPepId])
REFERENCES [dbo].[CDDGReasonNotPep] ([ReasonID])
GO
ALTER TABLE [dbo].[CDDGPep] CHECK CONSTRAINT [CDDGReasonNotPep_CDDGPEP_FK]
GO
ALTER TABLE [dbo].[CDDGPep]  WITH CHECK ADD  CONSTRAINT [CDDGSERVICEREQUESTTYPE_CDDGPEP_FK] FOREIGN KEY([ServiceRequestTypeId])
REFERENCES [dbo].[CDDGServiceRequestType] ([RequestID])
GO
ALTER TABLE [dbo].[CDDGPep] CHECK CONSTRAINT [CDDGSERVICEREQUESTTYPE_CDDGPEP_FK]
GO
ALTER TABLE [dbo].[CDDGPep]  WITH CHECK ADD  CONSTRAINT [CDDGWellsFargoBranch_CDDGPEP_FK] FOREIGN KEY([WFBranchId])
REFERENCES [dbo].[CDDGWellsFargoBranch] ([BranchID])
GO
ALTER TABLE [dbo].[CDDGPep] CHECK CONSTRAINT [CDDGWellsFargoBranch_CDDGPEP_FK]
GO
ALTER TABLE [dbo].[CDDGPepHistory]  WITH CHECK ADD  CONSTRAINT [CDDGBookingOffice_CDDGPepHistory_FK] FOREIGN KEY([BookingOfficeId])
REFERENCES [dbo].[CDDGBookingOffice] ([OfficeID])
GO
ALTER TABLE [dbo].[CDDGPepHistory] CHECK CONSTRAINT [CDDGBookingOffice_CDDGPepHistory_FK]
GO
ALTER TABLE [dbo].[CDDGPepHistory]  WITH CHECK ADD  CONSTRAINT [CDDGCOUNTRY_CDDGPepHistory_FK] FOREIGN KEY([CountryId])
REFERENCES [dbo].[CDDGCountry] ([CountryID])
GO
ALTER TABLE [dbo].[CDDGPepHistory] CHECK CONSTRAINT [CDDGCOUNTRY_CDDGPepHistory_FK]
GO
ALTER TABLE [dbo].[CDDGPepHistory]  WITH CHECK ADD  CONSTRAINT [cddgcustomer_CDDGPepHistory_fk] FOREIGN KEY([CustomerId])
REFERENCES [dbo].[CDDGCustomer] ([CustomerID])
GO
ALTER TABLE [dbo].[CDDGPepHistory] CHECK CONSTRAINT [cddgcustomer_CDDGPepHistory_fk]
GO
ALTER TABLE [dbo].[CDDGPepHistory]  WITH CHECK ADD  CONSTRAINT [CDDGPEPLEVEL_CDDGPepHistory_FK] FOREIGN KEY([PepLevelId])
REFERENCES [dbo].[CDDGPepLevel] ([PepLevelId])
GO
ALTER TABLE [dbo].[CDDGPepHistory] CHECK CONSTRAINT [CDDGPEPLEVEL_CDDGPepHistory_FK]
GO
ALTER TABLE [dbo].[CDDGPepHistory]  WITH CHECK ADD  CONSTRAINT [CDDGPEPRequestStatus_CDDGPepHistory_FK] FOREIGN KEY([PepRequestStatusId])
REFERENCES [dbo].[CDDGPEPRequestStatus] ([PepRequestStatusID])
GO
ALTER TABLE [dbo].[CDDGPepHistory] CHECK CONSTRAINT [CDDGPEPRequestStatus_CDDGPepHistory_FK]
GO
ALTER TABLE [dbo].[CDDGPepHistory]  WITH CHECK ADD  CONSTRAINT [CDDGPepType_CDDGPepHistory_FK] FOREIGN KEY([PepTypeId])
REFERENCES [dbo].[CDDGPepType] ([PepTypeId])
GO
ALTER TABLE [dbo].[CDDGPepHistory] CHECK CONSTRAINT [CDDGPepType_CDDGPepHistory_FK]
GO
ALTER TABLE [dbo].[CDDGPepHistory]  WITH CHECK ADD  CONSTRAINT [CDDGReasonNotPep_CDDGPepHistory_FK] FOREIGN KEY([ReasonNotPepId])
REFERENCES [dbo].[CDDGReasonNotPep] ([ReasonID])
GO
ALTER TABLE [dbo].[CDDGPepHistory] CHECK CONSTRAINT [CDDGReasonNotPep_CDDGPepHistory_FK]
GO
ALTER TABLE [dbo].[CDDGPepHistory]  WITH CHECK ADD  CONSTRAINT [CDDGSERVICEREQUESTTYPE_CDDGPepHistory_FK] FOREIGN KEY([ServiceRequestTypeId])
REFERENCES [dbo].[CDDGServiceRequestType] ([RequestID])
GO
ALTER TABLE [dbo].[CDDGPepHistory] CHECK CONSTRAINT [CDDGSERVICEREQUESTTYPE_CDDGPepHistory_FK]
GO
ALTER TABLE [dbo].[CDDGPepHistory]  WITH CHECK ADD  CONSTRAINT [CDDGWellsFargoBranch_CDDGPepHistory_FK] FOREIGN KEY([WFBranchId])
REFERENCES [dbo].[CDDGWellsFargoBranch] ([BranchID])
GO
ALTER TABLE [dbo].[CDDGPepHistory] CHECK CONSTRAINT [CDDGWellsFargoBranch_CDDGPepHistory_FK]
GO
ALTER TABLE [dbo].[CDDGPepRequestAutoAssignment]  WITH CHECK ADD  CONSTRAINT [cddguser_cddgpeprequestautoassignment_fk] FOREIGN KEY([UserId])
REFERENCES [dbo].[CDDGUser] ([UserID])
GO
ALTER TABLE [dbo].[CDDGPepRequestAutoAssignment] CHECK CONSTRAINT [cddguser_cddgpeprequestautoassignment_fk]
GO
ALTER TABLE [dbo].[CDDGPrimaryPep]  WITH CHECK ADD  CONSTRAINT [CDDGBSAApproval_CDDGPrimaryPep_FK] FOREIGN KEY([CountryBSAApprovalId])
REFERENCES [dbo].[CDDGBSAApproval] ([BSAApprovalId])
GO
ALTER TABLE [dbo].[CDDGPrimaryPep] CHECK CONSTRAINT [CDDGBSAApproval_CDDGPrimaryPep_FK]
GO
ALTER TABLE [dbo].[CDDGPrimaryPep]  WITH CHECK ADD  CONSTRAINT [CDDGBSAApproval_CDDGPrimaryPep_FK2] FOREIGN KEY([AssociatedCountryBSAApprovalId])
REFERENCES [dbo].[CDDGBSAApproval] ([BSAApprovalId])
GO
ALTER TABLE [dbo].[CDDGPrimaryPep] CHECK CONSTRAINT [CDDGBSAApproval_CDDGPrimaryPep_FK2]
GO
ALTER TABLE [dbo].[CDDGPrimaryPep]  WITH CHECK ADD  CONSTRAINT [CDDGChangeRequest_CDDGPrimaryPep_FK] FOREIGN KEY([ChangeRequestID])
REFERENCES [dbo].[CDDGChangeRequest] ([ChangeRequestId])
GO
ALTER TABLE [dbo].[CDDGPrimaryPep] CHECK CONSTRAINT [CDDGChangeRequest_CDDGPrimaryPep_FK]
GO
ALTER TABLE [dbo].[CDDGPrimaryPep]  WITH CHECK ADD  CONSTRAINT [CDDGCountry_CDDGPrimaryPep_FK] FOREIGN KEY([PrimaryPepAssociatedCountryId])
REFERENCES [dbo].[CDDGCountry] ([CountryID])
GO
ALTER TABLE [dbo].[CDDGPrimaryPep] CHECK CONSTRAINT [CDDGCountry_CDDGPrimaryPep_FK]
GO
ALTER TABLE [dbo].[CDDGPrimaryPep]  WITH CHECK ADD  CONSTRAINT [CDDGCOUNTRY_CDDGPrimaryPep_FK2] FOREIGN KEY([PrimaryPepCountryId])
REFERENCES [dbo].[CDDGCountry] ([CountryID])
GO
ALTER TABLE [dbo].[CDDGPrimaryPep] CHECK CONSTRAINT [CDDGCOUNTRY_CDDGPrimaryPep_FK2]
GO
ALTER TABLE [dbo].[CDDGPrimaryPep]  WITH CHECK ADD  CONSTRAINT [CDDGPep_CDDGPrimaryPep_FK] FOREIGN KEY([PepId])
REFERENCES [dbo].[CDDGPep] ([PepId])
GO
ALTER TABLE [dbo].[CDDGPrimaryPep] CHECK CONSTRAINT [CDDGPep_CDDGPrimaryPep_FK]
GO
ALTER TABLE [dbo].[CDDGPrimaryPep]  WITH CHECK ADD  CONSTRAINT [cddgpep_CDDGPrimaryPep_fk1] FOREIGN KEY([PepRequestStatusID])
REFERENCES [dbo].[CDDGPEPRequestStatus] ([PepRequestStatusID])
GO
ALTER TABLE [dbo].[CDDGPrimaryPep] CHECK CONSTRAINT [cddgpep_CDDGPrimaryPep_fk1]
GO
ALTER TABLE [dbo].[CDDGPrimaryPep]  WITH CHECK ADD  CONSTRAINT [CDDGPrimaryPepAssociationOption_CDDGPrimaryPep_FK] FOREIGN KEY([PrimaryPepAssociationId])
REFERENCES [dbo].[CDDGPrimaryPepAssociationOption] ([AssociationOptionId])
GO
ALTER TABLE [dbo].[CDDGPrimaryPep] CHECK CONSTRAINT [CDDGPrimaryPepAssociationOption_CDDGPrimaryPep_FK]
GO
ALTER TABLE [dbo].[CDDGPrimaryPep]  WITH CHECK ADD  CONSTRAINT [CDDGPrimaryPepPosition_CDDGPrimaryPep_FK] FOREIGN KEY([PrimaryPepPositionId])
REFERENCES [dbo].[CDDGPrimaryPepPosition] ([PrimaryPepPositionId])
GO
ALTER TABLE [dbo].[CDDGPrimaryPep] CHECK CONSTRAINT [CDDGPrimaryPepPosition_CDDGPrimaryPep_FK]
GO
ALTER TABLE [dbo].[CDDGPrimaryPepAssociatedCountryLob]  WITH CHECK ADD  CONSTRAINT [CDDGLOB_CDDGPRIMARYPEPASSOCIATEDCOUNTRYLOB_FK] FOREIGN KEY([LobId])
REFERENCES [dbo].[CDDGLob] ([LobId])
GO
ALTER TABLE [dbo].[CDDGPrimaryPepAssociatedCountryLob] CHECK CONSTRAINT [CDDGLOB_CDDGPRIMARYPEPASSOCIATEDCOUNTRYLOB_FK]
GO
ALTER TABLE [dbo].[CDDGPrimaryPepAssociatedCountryLob]  WITH CHECK ADD  CONSTRAINT [CDDGPRIMARYPEP_CDDGPRIMARYPEPASSOCIATEDCOUNTRYLOB_FK] FOREIGN KEY([PrimaryPepId])
REFERENCES [dbo].[CDDGPrimaryPep] ([PrimaryPepId])
GO
ALTER TABLE [dbo].[CDDGPrimaryPepAssociatedCountryLob] CHECK CONSTRAINT [CDDGPRIMARYPEP_CDDGPRIMARYPEPASSOCIATEDCOUNTRYLOB_FK]
GO
ALTER TABLE [dbo].[CDDGPrimaryPepAssociationOption]  WITH NOCHECK ADD  CONSTRAINT [CDDGPepAssociation_CDDGPepAssociationOption_FK] FOREIGN KEY([AssociationId])
REFERENCES [dbo].[CDDGPrimaryPepAssociation] ([AssociationId])
GO
ALTER TABLE [dbo].[CDDGPrimaryPepAssociationOption] CHECK CONSTRAINT [CDDGPepAssociation_CDDGPepAssociationOption_FK]
GO
ALTER TABLE [dbo].[CDDGPrimaryPepCountryLob]  WITH CHECK ADD  CONSTRAINT [CDDGLOB_CDDGPRIMARYPEPLOB_FK] FOREIGN KEY([LobId])
REFERENCES [dbo].[CDDGLob] ([LobId])
GO
ALTER TABLE [dbo].[CDDGPrimaryPepCountryLob] CHECK CONSTRAINT [CDDGLOB_CDDGPRIMARYPEPLOB_FK]
GO
ALTER TABLE [dbo].[CDDGPrimaryPepCountryLob]  WITH CHECK ADD  CONSTRAINT [CDDGPRIMARYPEP_CDDGPRIMARYPEPLOB_FK] FOREIGN KEY([PrimaryPepId])
REFERENCES [dbo].[CDDGPrimaryPep] ([PrimaryPepId])
GO
ALTER TABLE [dbo].[CDDGPrimaryPepCountryLob] CHECK CONSTRAINT [CDDGPRIMARYPEP_CDDGPRIMARYPEPLOB_FK]
GO
ALTER TABLE [dbo].[CDDGRequestAssignment]  WITH CHECK ADD  CONSTRAINT [CDDGChangeRequest_cddgrequestassignment_FK] FOREIGN KEY([ChangeRequestID])
REFERENCES [dbo].[CDDGChangeRequest] ([ChangeRequestId])
GO
ALTER TABLE [dbo].[CDDGRequestAssignment] CHECK CONSTRAINT [CDDGChangeRequest_cddgrequestassignment_FK]
GO
ALTER TABLE [dbo].[CDDGRequestAssignment]  WITH CHECK ADD  CONSTRAINT [cddgpep_cddgrequestassignment_fk] FOREIGN KEY([PepId])
REFERENCES [dbo].[CDDGPep] ([PepId])
GO
ALTER TABLE [dbo].[CDDGRequestAssignment] CHECK CONSTRAINT [cddgpep_cddgrequestassignment_fk]
GO
ALTER TABLE [dbo].[CDDGRequestAssignment]  WITH CHECK ADD  CONSTRAINT [cddgpep_cddgrequestassignment_fk1] FOREIGN KEY([PepRequestStatusID])
REFERENCES [dbo].[CDDGPEPRequestStatus] ([PepRequestStatusID])
GO
ALTER TABLE [dbo].[CDDGRequestAssignment] CHECK CONSTRAINT [cddgpep_cddgrequestassignment_fk1]
GO
ALTER TABLE [dbo].[CDDGRequestAssignment]  WITH CHECK ADD  CONSTRAINT [cddguser_cddgrequestassignment_fk] FOREIGN KEY([UserId])
REFERENCES [dbo].[CDDGUser] ([UserID])
GO
ALTER TABLE [dbo].[CDDGRequestAssignment] CHECK CONSTRAINT [cddguser_cddgrequestassignment_fk]
GO
ALTER TABLE [dbo].[CDDGRoleGroups]  WITH CHECK ADD  CONSTRAINT [CDDGGroup_CDDGRoleGroups_FK] FOREIGN KEY([GroupID])
REFERENCES [dbo].[CDDGGroup] ([GroupID])
GO
ALTER TABLE [dbo].[CDDGRoleGroups] CHECK CONSTRAINT [CDDGGroup_CDDGRoleGroups_FK]
GO
ALTER TABLE [dbo].[CDDGRoleGroups]  WITH CHECK ADD  CONSTRAINT [CDDGRole_CDDGRoleGroups_FK] FOREIGN KEY([RoleID])
REFERENCES [dbo].[CDDGRole] ([RoleID])
GO
ALTER TABLE [dbo].[CDDGRoleGroups] CHECK CONSTRAINT [CDDGRole_CDDGRoleGroups_FK]
GO
ALTER TABLE [dbo].[CDDGRoleView]  WITH CHECK ADD  CONSTRAINT [CDDGROLE_CDDGROLEVIEW_FK] FOREIGN KEY([RoleID])
REFERENCES [dbo].[CDDGRole] ([RoleID])
GO
ALTER TABLE [dbo].[CDDGRoleView] CHECK CONSTRAINT [CDDGROLE_CDDGROLEVIEW_FK]
GO
ALTER TABLE [dbo].[CDDGRoleView]  WITH CHECK ADD  CONSTRAINT [CDDGVIEW_CDDGROLEVIEW_FK] FOREIGN KEY([ViewID])
REFERENCES [dbo].[CDDGView] ([ViewID])
GO
ALTER TABLE [dbo].[CDDGRoleView] CHECK CONSTRAINT [CDDGVIEW_CDDGROLEVIEW_FK]
GO
ALTER TABLE [dbo].[CDDGRoleViewAccess]  WITH CHECK ADD  CONSTRAINT [CDDGACCESS_CDDGROLEVIEWACCESS_FK] FOREIGN KEY([AccessID])
REFERENCES [dbo].[CDDGAccess] ([AccessID])
GO
ALTER TABLE [dbo].[CDDGRoleViewAccess] CHECK CONSTRAINT [CDDGACCESS_CDDGROLEVIEWACCESS_FK]
GO
ALTER TABLE [dbo].[CDDGRoleViewAccess]  WITH CHECK ADD  CONSTRAINT [CDDGROLEVIEW_CDDGROLEVIEWACCESS_FK] FOREIGN KEY([RoleViewID])
REFERENCES [dbo].[CDDGRoleView] ([RoleViewID])
GO
ALTER TABLE [dbo].[CDDGRoleViewAccess] CHECK CONSTRAINT [CDDGROLEVIEW_CDDGROLEVIEWACCESS_FK]
GO
ALTER TABLE [dbo].[CDDGUser]  WITH NOCHECK ADD  CONSTRAINT [CDDGUSERCITY_CDDGUSER_FK] FOREIGN KEY([CityID])
REFERENCES [dbo].[CDDGUserCity] ([CityID])
GO
ALTER TABLE [dbo].[CDDGUser] CHECK CONSTRAINT [CDDGUSERCITY_CDDGUSER_FK]
GO
ALTER TABLE [dbo].[CDDGUserCity]  WITH CHECK ADD  CONSTRAINT [CDDGUSERSTATE_CDDGUSERCITY_FK] FOREIGN KEY([StateID])
REFERENCES [dbo].[CDDGUserState] ([StateID])
GO
ALTER TABLE [dbo].[CDDGUserCity] CHECK CONSTRAINT [CDDGUSERSTATE_CDDGUSERCITY_FK]
GO
ALTER TABLE [dbo].[CDDGUserRoles]  WITH CHECK ADD  CONSTRAINT [CDDGROLE_CDDGUSERROLES_FK] FOREIGN KEY([RoleID])
REFERENCES [dbo].[CDDGRole] ([RoleID])
GO
ALTER TABLE [dbo].[CDDGUserRoles] CHECK CONSTRAINT [CDDGROLE_CDDGUSERROLES_FK]
GO
ALTER TABLE [dbo].[CDDGUserRoles]  WITH CHECK ADD  CONSTRAINT [CDDGUSER_CDDGUSERROLES_FK] FOREIGN KEY([UserID])
REFERENCES [dbo].[CDDGUser] ([UserID])
GO
ALTER TABLE [dbo].[CDDGUserRoles] CHECK CONSTRAINT [CDDGUSER_CDDGUSERROLES_FK]
GO
ALTER TABLE [dbo].[CDDGUserState]  WITH CHECK ADD  CONSTRAINT [CDDGUSERCOUNTRY_CDDGUSERSTATE_FK] FOREIGN KEY([CountryID])
REFERENCES [dbo].[CDDGUserCountry] ([CountryID])
GO
ALTER TABLE [dbo].[CDDGUserState] CHECK CONSTRAINT [CDDGUSERCOUNTRY_CDDGUSERSTATE_FK]
GO
ALTER TABLE [dbo].[TableChild]  WITH CHECK ADD FOREIGN KEY([PID])
REFERENCES [dbo].[TableParent] ([ID])
GO
ALTER TABLE [dbo].[TableParentPrimary]  WITH CHECK ADD FOREIGN KEY([Child])
REFERENCES [dbo].[TableChild] ([ID])
GO
ALTER TABLE [dbo].[TableParentPrimary]  WITH CHECK ADD FOREIGN KEY([PID])
REFERENCES [dbo].[TableParent] ([ID])
GO
ALTER TABLE [dbo].[WatchListDetail]  WITH NOCHECK ADD  CONSTRAINT [WatchListDetail_Entity_FK] FOREIGN KEY([EntityTypeID])
REFERENCES [dbo].[EntityTypes] ([ID])
GO
ALTER TABLE [dbo].[WatchListDetail] CHECK CONSTRAINT [WatchListDetail_Entity_FK]
GO
ALTER TABLE [dbo].[WatchListDetail]  WITH NOCHECK ADD  CONSTRAINT [WatchListDetail_WL_FK] FOREIGN KEY([WLID])
REFERENCES [dbo].[WatchLists] ([WLID])
GO
ALTER TABLE [dbo].[WatchListDetail] CHECK CONSTRAINT [WatchListDetail_WL_FK]
GO
ALTER TABLE [dbo].[WatchListDetailAddresses]  WITH NOCHECK ADD  CONSTRAINT [WatchListDetailAddresses_WL_FK] FOREIGN KEY([WLID])
REFERENCES [dbo].[WatchLists] ([WLID])
GO
ALTER TABLE [dbo].[WatchListDetailAddresses] CHECK CONSTRAINT [WatchListDetailAddresses_WL_FK]
GO
ALTER TABLE [dbo].[WatchListDetailAddresses]  WITH NOCHECK ADD  CONSTRAINT [WatchListDetailAddresses_WLDetail_FK] FOREIGN KEY([WLDetailID])
REFERENCES [dbo].[WatchListDetail] ([ID])
GO
ALTER TABLE [dbo].[WatchListDetailAddresses] CHECK CONSTRAINT [WatchListDetailAddresses_WLDetail_FK]
GO
ALTER TABLE [dbo].[WatchListDetailAKAs]  WITH NOCHECK ADD  CONSTRAINT [WatchListDetailAKAs_WL_FK] FOREIGN KEY([WLID])
REFERENCES [dbo].[WatchLists] ([WLID])
GO
ALTER TABLE [dbo].[WatchListDetailAKAs] CHECK CONSTRAINT [WatchListDetailAKAs_WL_FK]
GO
ALTER TABLE [dbo].[WatchListDetailAKAs]  WITH NOCHECK ADD  CONSTRAINT [WatchListDetailAKAs_WLDetail_FK] FOREIGN KEY([WLDetailID])
REFERENCES [dbo].[WatchListDetail] ([ID])
GO
ALTER TABLE [dbo].[WatchListDetailAKAs] CHECK CONSTRAINT [WatchListDetailAKAs_WLDetail_FK]
GO
