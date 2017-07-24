  foreach (CDDGEcn item in PreviousApprovedData)
                    {
                        EcnEntity ecna = new EcnEntity();

                        ecna.PEPID = item.PepId;

                        ecna.ECN = item.Ecn;
                        ecna.IsFlagged = item.IsFlagged;

                        ecna.DateFlagged = item.DateFlagged;


                        ecna.PepRequestStatusID = item.PepRequestStatusID;

                        ecna.EcnSeqVal = item.EcnSeqVal;

                        ecna.EcnSeqValNum = item.EcnSeqValNum;

                        ecna.CreatedBy = item.CreatedBY;

                        ecna.CreatedTS = DateTime.Now;

                        ecna.ChangeRequestID = item.ChangeRequestID;


                        ecna = AddNewEcn(ecna);
                        
                    }
