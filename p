public bool PrimaryPepEquals(PrimaryPepEntity x, PrimaryPepEntity y)
        {
            ChangedProperties = new Dictionary<string, List<string>>();
            var Xlist = x;
            var Ylist = y;
            var propList = typeof(PrimaryPepEntity).GetProperties();
            var modifiedProps = new List<string>();
            var changedprimarypep = new StringBuilder();
            if (Xlist != null || Ylist != null)
            {
                foreach (var p in propList)
                {
                    if (p.PropertyType.IsValueType || p.PropertyType == typeof(string) || p.PropertyType == typeof(Nullable<DateTime>) || p.PropertyType == typeof(DateTime))
                    {
                        var c = (p.GetValue(Ylist) == null) ? string.Empty : p.GetValue(Ylist);
                        var o = (p.GetValue(Xlist) == null) ? string.Empty : p.GetValue(Xlist);

                        if (!Equals(c, o))
                        {
                            if (p.Name.Equals("PrimaryPepId"))
                            {
                                changedprimarypep.Append(c.ToString() + "|");
                            }
                            changedprimarypep.Append(p.Name + "|");

                        }

                    }
                    else if (p.Name.Contains("CDDGPrimaryPepAssociatedCountryLobs"))
                    {
                        var Xlistprimarypassociatedlob = p.GetValue(Xlist) as IList;
                        var Ylistprimarypassociatedlob = p.GetValue(Ylist) as IList;
                        if (Ylistprimarypassociatedlob.Count > 0)
                        {
                            var strLobs = (Ylistprimarypassociatedlob as IList<PrimaryPepAssociatedCountryLobEntity>).Select(i => i.LobId.ToString()).ToList().Except((Xlistprimarypassociatedlob as IList<PrimaryPepAssociatedCountryLobEntity>).Select(i => i.LobId.ToString()).ToList()).ToList();
                            if (strLobs.Count > 0)
                                changedprimarypep.Append(p.Name + "|");
                        }

                    }

                    else if (p.Name.Contains("CDDGPrimaryPepCountryLobs"))
                    {
                        var Xlistprimarypassociatedlob = p.GetValue(Xlist) as IList;
                        var Ylistprimarypassociatedlob = p.GetValue(Ylist) as IList;
                        if (Ylistprimarypassociatedlob.Count > 0)
                        {
                            var strLobs = (Ylistprimarypassociatedlob as IList<PrimaryPepCountryLobEntity>).Select(i => i.LobId.ToString()).ToList().Except((Xlistprimarypassociatedlob as IList<PrimaryPepCountryLobEntity>).Select(i => i.LobId.ToString()).ToList()).ToList();
                            if (strLobs.Count > 0)
                                changedprimarypep.Append(p.Name + "|");
                        }

                    }

                }
                modifiedProps.Add(changedprimarypep.ToString());
                if (modifiedProps.Count > 0)
                {
                    if (ChangedProperties.ContainsKey("PrimaryPeps"))
                    {
                        ChangedProperties.Remove("PrimaryPeps");
                        ChangedProperties.Add("PrimaryPeps", modifiedProps);
                    }
                    else
                    {
                        ChangedProperties.Add("PrimaryPeps", modifiedProps);
                    }

                }


            }


            return (ChangedProperties.Count == 0);

        }
