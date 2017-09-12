using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WF.ERMT.Application.Entities.CustomEntities;

namespace WF.ERMT.Application.Business
{
    public class EqualityComparer : IEqualityComparer<PEPEntity>
    {

        public Dictionary<string, List<string>> ChangedProperties { get; private set; }

        public Dictionary<string, string> changedprimaryproperties { get; private set; }

        
        private string GetObjectValue<T>(T obj, string PropName)
        {
            if (obj.GetType().GetProperty(PropName).GetValue(obj) == null)
                return string.Empty;
            else
                return obj.GetType().GetProperty(PropName).GetValue(obj).ToString();
        }

        public bool Equals(PEPEntity x, PEPEntity y)
        {

            var propList = typeof(PEPEntity).GetProperties();
            ChangedProperties = new Dictionary<string, List<string>>();

            foreach (var prop in propList)
            {

                if (prop.PropertyType == typeof(string) || prop.PropertyType == typeof(Nullable<Boolean>) || prop.PropertyType == typeof(Int32) || prop.PropertyType == typeof(Nullable<int>) || prop.PropertyType == typeof(Nullable<DateTime>) || prop.PropertyType == typeof(DateTime))
                {
                    var xValue = GetObjectValue<PEPEntity>(x, prop.Name);
                    var yValue = GetObjectValue<PEPEntity>(y, prop.Name);

                    if (!Equals(xValue, yValue))
                    {
                        ChangedProperties.Add(prop.Name, new List<string>() { yValue.ToString() });
                    }
                }
                else if (prop.PropertyType.Name.StartsWith(typeof(IList).Name) || prop.PropertyType.Name.StartsWith(typeof(ICollection).Name))
                {
                    if (!prop.PropertyType.GetGenericArguments()[0].Name.StartsWith("String"))
                    {
                        var Xlist = prop.GetValue(x) as IList;
                        var Ylist = prop.GetValue(y) as IList;

                        if (prop.Name.Equals("Ecns", StringComparison.CurrentCultureIgnoreCase))
                        {
                            if (Xlist.Count > 0 || Ylist.Count > 0)
                            {
                                var strEcns = (Ylist as IList<EcnEntity>).Select(i => i.ECN).ToList().Except((Xlist as IList<EcnEntity>).Select(i => i.ECN).ToList()).ToList();
                                if (strEcns.Count > 0) ChangedProperties.Add(prop.Name, strEcns);
                            }
                        }
                        else if (prop.Name.Equals("LobPeps", StringComparison.CurrentCultureIgnoreCase))
                        {
                            if (Xlist.Count > 0 || Ylist.Count > 0)
                            {
                                var strLobs = (Ylist as IList<LobPepEntity>).Select(i => i.LobId.ToString()).ToList().Except((Xlist as IList<LobPepEntity>).Select(i => i.LobId.ToString()).ToList()).ToList();
                                if (strLobs.Count > 0) ChangedProperties.Add(prop.Name, strLobs);
                            }
                        }
                        else if (prop.Name.Equals("Attachments", StringComparison.CurrentCultureIgnoreCase))
                        {
                            if (Xlist.Count > 0 || Ylist.Count > 0)
                            {
                                var strattachments = (Ylist as IList<AttachmentEntity>).Select(i => i.FileName).ToList().Except((Xlist as IList<AttachmentEntity>).Select(i => i.FileName).ToList()).ToList();
                                if (strattachments.Count > 0) ChangedProperties.Add(prop.Name, strattachments);
                            }
                        }

                        else if (prop.Name.Equals("PrimaryPeps", StringComparison.CurrentCultureIgnoreCase))
                        {
                            var modifiedProps = new List<string>();
                            var changedprimarypep = new StringBuilder();
                            if (Xlist.Count > 0 || Ylist.Count > 0)
                            {
                                //var strPrimarypeps = (Ylist as IList<PrimaryPepEntity>).Where(i=>i.PreviousPrimaryPepId==)).ToList().Except((Xlist as IList<PrimaryPepEntity>).Select(i => i.PrimaryPepId.ToString()).ToList()).ToList();
                                foreach (var priamry in (Xlist as IList<PrimaryPepEntity>))
                                {
                                    var tocompare = (Ylist as IList<PrimaryPepEntity>).Where(i => i.PreviousPrimaryPepId == priamry.PrimaryPepId).FirstOrDefault();
                                    if (tocompare != null)
                                    {
                                        foreach (var p in prop.PropertyType.GetGenericArguments()[0].GetProperties())
                                        {

　
                                            if (p.PropertyType.IsValueType || p.PropertyType == typeof(string) || p.PropertyType == typeof(Nullable<DateTime>) || p.PropertyType == typeof(DateTime))
                                            {
                                                var c = (p.GetValue(tocompare) == null) ? string.Empty : p.GetValue(tocompare);
                                                var o = (p.GetValue(priamry) == null) ? string.Empty : p.GetValue(priamry);

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
                                                var Xlistprimarypassociatedlob = p.GetValue(priamry) as IList;
                                                var Ylistprimarypassociatedlob = p.GetValue(tocompare) as IList;
                                                if(Ylistprimarypassociatedlob.Count > 0)
                                                {
                                                    var strLobs = (Ylistprimarypassociatedlob as IList<PrimaryPepAssociatedCountryLobEntity>).Select(i => i.LobId.ToString()).ToList().Except((Xlistprimarypassociatedlob as IList<PrimaryPepAssociatedCountryLobEntity>).Select(i => i.LobId.ToString()).ToList()).ToList();
                                                    if(strLobs.Count>0)
                                                        changedprimarypep.Append(p.Name + "|");
                                                }

                                            }

                                            else if (p.Name.Contains("CDDGPrimaryPepCountryLobs"))
                                            {
                                                var Xlistprimarypassociatedlob = p.GetValue(priamry) as IList;
                                                var Ylistprimarypassociatedlob = p.GetValue(tocompare) as IList;
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
                                            if (ChangedProperties.ContainsKey(prop.Name))
                                            {
                                                ChangedProperties.Remove(prop.Name);
                                                ChangedProperties.Add(prop.Name, modifiedProps);
                                            }
                                            else
                                            {
                                                ChangedProperties.Add(prop.Name, modifiedProps);
                                            }

                                        }
                                    }
                                    else
                                    {
                                        foreach (var p in prop.PropertyType.GetGenericArguments()[0].GetProperties())
                                        {
                                            if (p.Name.Equals("PrimaryPepId"))
                                            {
                                                changedprimarypep.Append(p.GetValue(priamry) + "|");
                                            }
                                            changedprimarypep.Append(p.Name + "|");
                                        }

　
                                        modifiedProps.Add(changedprimarypep.ToString());
                                        if (modifiedProps.Count > 0)
                                        {
                                            if (ChangedProperties.ContainsKey(prop.Name))
                                            {
                                                ChangedProperties.Remove(prop.Name);
                                                ChangedProperties.Add(prop.Name, modifiedProps);
                                            }
                                            else
                                            {
                                                ChangedProperties.Add(prop.Name, modifiedProps);
                                            }
                                        }
                                    }
                                  

                                }

                                
                                //if (strPrimarypeps.Count > 0) ChangedProperties.Add(prop.Name, strPrimarypeps);
                            }
                        }

                    }
                }
                else if (prop.PropertyType.IsClass && !prop.PropertyType.Equals(typeof(List<string>)) && !prop.PropertyType.Equals(typeof(List<int>)))
                {
                    var modifiedProps = new List<string>();

                    foreach (var p in prop.PropertyType.GetProperties())
                    {

                        if (p.PropertyType.IsValueType || p.PropertyType == typeof(string) || p.PropertyType == typeof(Nullable<DateTime>) || p.PropertyType == typeof(DateTime))
                        {
                            var c = (prop.GetValue(x) == null) ? string.Empty : prop.GetValue(x).GetType().GetProperty(p.Name).GetValue(prop.GetValue(x));
                            var o = (prop.GetValue(y) == null) ? string.Empty : prop.GetValue(y).GetType().GetProperty(p.Name).GetValue(prop.GetValue(y));

                            if (!Equals(c, o))
                                modifiedProps.Add(p.Name);
                        }
                    }
                    if (modifiedProps.Count > 0) ChangedProperties.Add(prop.Name, modifiedProps);
                }

　
　
                //switch (prop.PropertyType)
                //{
                //    case prop.PropertyType == typeof(string):
                //        var c = GetObjectValue<PEPEntity>(x, prop.Name);
                //        var o = GetObjectValue<PEPEntity>(y, prop.Name);
                //        break;
                //    case prop.GetType() == typeof(Int32):

                //        break;
                //    case prop.GetType() == typeof(ICollection):

                //        break;
                //    case typeof(IList):

                //        break;

                //}

            }

            return (ChangedProperties.Count == 0);

        }

        public bool CREquals(PEPEntity x, PEPEntity y)
        {

            var propList = typeof(PEPEntity).GetProperties();
            ChangedProperties = new Dictionary<string, List<string>>();

            try
            {
                foreach (var prop in propList)
                {

                    if (prop.PropertyType == typeof(string) || prop.PropertyType == typeof(Nullable<Boolean>) || prop.PropertyType == typeof(Int32) || prop.PropertyType == typeof(Nullable<int>) || prop.PropertyType == typeof(Nullable<DateTime>) || prop.PropertyType == typeof(DateTime))
                    {
                        var xValue = GetObjectValue<PEPEntity>(x, prop.Name);
                        var yValue = GetObjectValue<PEPEntity>(y, prop.Name);

                        if (!Equals(xValue, yValue))
                        {
                            ChangedProperties.Add(prop.Name, new List<string>() { yValue.ToString() });
                        }
                    }
                    else if (prop.PropertyType.Name.StartsWith(typeof(IList).Name) || prop.PropertyType.Name.StartsWith(typeof(ICollection).Name))
                    {
                        if (!prop.PropertyType.GetGenericArguments()[0].Name.StartsWith("String"))
                        {
                            var Xlist = prop.GetValue(x) as IList;
                            var Ylist = prop.GetValue(y) as IList;

　
                            if (prop.Name.Equals("Ecns", StringComparison.CurrentCultureIgnoreCase))
                            {
                                if (Ylist != null)
                                {
                                    if (Xlist.Count > 0 || Ylist.Count > 0)
                                    {
                                        var strEcns = (Ylist as IList<EcnEntity>).Select(i => i.ECN).ToList().Except((Xlist as IList<EcnEntity>).Select(i => i.ECN).ToList()).ToList();
                                        if (strEcns.Count > 0) ChangedProperties.Add(prop.Name, strEcns);
                                    }
                                }
                            }
                            else if (prop.Name.Equals("LobPeps", StringComparison.CurrentCultureIgnoreCase))
                            {
                                if (Ylist != null)
                                {
                                    if (Xlist.Count > 0 || Ylist.Count > 0)
                                    {
                                        var strLobs = (Ylist as IList<LobPepEntity>).Select(i => i.LobId.ToString()).ToList().Except((Xlist as IList<LobPepEntity>).Select(i => i.LobId.ToString()).ToList()).ToList();
                                        if (strLobs.Count > 0) ChangedProperties.Add(prop.Name, strLobs);
                                    }
                                }
                            }
                            else if (prop.Name.Equals("Attachments", StringComparison.CurrentCultureIgnoreCase))
                            {
                                if (Ylist != null)
                                {
                                    if (Xlist.Count > 0 || Ylist.Count > 0)
                                    {
                                        var strattachments = (Ylist as IList<AttachmentEntity>).Select(i => i.FileName).ToList().Except((Xlist as IList<AttachmentEntity>).Select(i => i.FileName).ToList()).ToList();
                                        if (strattachments.Count > 0) ChangedProperties.Add(prop.Name, strattachments);
                                    }
                                }
                            }

                            else if (prop.Name.Equals("PrimaryPeps", StringComparison.CurrentCultureIgnoreCase))
                            {
                                var modifiedProps = new List<string>();
                                //var changedprimarypep = new StringBuilder();

                                if (Ylist != null)
                                {
                                    if (Xlist.Count > 0 || Ylist.Count > 0)
                                    {
                                        //var strPrimarypeps = (Ylist as IList<PrimaryPepEntity>).Where(i=>i.PreviousPrimaryPepId==)).ToList().Except((Xlist as IList<PrimaryPepEntity>).Select(i => i.PrimaryPepId.ToString()).ToList()).ToList();
                                        foreach (var priamry in (Xlist as IList<PrimaryPepEntity>))
                                        {
                                            var changedprimarypep = new StringBuilder();
                                            var tocompare = (Ylist as IList<PrimaryPepEntity>).Where(i => i.PreviousPrimaryPepId == priamry.PrimaryPepId).FirstOrDefault();
                                            if (tocompare != null)
                                            {
                                                foreach (var p in prop.PropertyType.GetGenericArguments()[0].GetProperties())
                                                {

　
                                                    if (p.PropertyType.IsValueType || p.PropertyType == typeof(string) || p.PropertyType == typeof(Nullable<DateTime>) || p.PropertyType == typeof(DateTime))
                                                    {
                                                        var c = (p.GetValue(tocompare) == null) ? string.Empty : p.GetValue(tocompare);
                                                        var o = (p.GetValue(priamry) == null) ? string.Empty : p.GetValue(priamry);

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
                                                        var Xlistprimarypassociatedlob = p.GetValue(priamry) as IList;
                                                        var Ylistprimarypassociatedlob = p.GetValue(tocompare) as IList;
                                                        if (Ylistprimarypassociatedlob.Count > 0)
                                                        {
                                                            var strLobs = (Ylistprimarypassociatedlob as IList<PrimaryPepAssociatedCountryLobEntity>).Select(i => i.LobId.ToString()).ToList().Except((Xlistprimarypassociatedlob as IList<PrimaryPepAssociatedCountryLobEntity>).Select(i => i.LobId.ToString()).ToList()).ToList();
                                                            if (strLobs.Count > 0)
                                                                changedprimarypep.Append(p.Name + "|");
                                                        }

                                                    }

                                                    else if (p.Name.Contains("CDDGPrimaryPepCountryLobs"))
                                                    {
                                                        var Xlistprimarypassociatedlob = p.GetValue(priamry) as IList;
                                                        var Ylistprimarypassociatedlob = p.GetValue(tocompare) as IList;
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
                                                    if (ChangedProperties.ContainsKey(prop.Name))
                                                    {
                                                        ChangedProperties.Remove(prop.Name);
                                                        ChangedProperties.Add(prop.Name, modifiedProps);
                                                    }
                                                    else
                                                    {
                                                        ChangedProperties.Add(prop.Name, modifiedProps);
                                                    }

                                                }
                                            }
                                            else
                                            {
                                                foreach (var p in prop.PropertyType.GetGenericArguments()[0].GetProperties())
                                                {
                                                    if (p.Name.Equals("PrimaryPepId"))
                                                    {
                                                        changedprimarypep.Append(p.GetValue(priamry) + "|");
                                                    }
                                                    changedprimarypep.Append(p.Name + "|");
                                                }

　
                                                modifiedProps.Add(changedprimarypep.ToString());
                                                if (modifiedProps.Count > 0)
                                                {
                                                    if (ChangedProperties.ContainsKey(prop.Name))
                                                    {
                                                        ChangedProperties.Remove(prop.Name);
                                                        ChangedProperties.Add(prop.Name, modifiedProps);
                                                    }
                                                    else
                                                    {
                                                        ChangedProperties.Add(prop.Name, modifiedProps);
                                                    }
                                                }
                                            }

　
                                        }

                                        //for loop ends
                                        //if (strPrimarypeps.Count > 0) ChangedProperties.Add(prop.Name, strPrimarypeps);
                                    }
                                }

                            }
                        }
                    }
                    else if (prop.PropertyType.IsClass && !prop.PropertyType.Equals(typeof(List<string>)) && !prop.PropertyType.Equals(typeof(List<int>)))
                    {
                        var modifiedProps = new List<string>();

                        foreach (var p in prop.PropertyType.GetProperties())
                        {

                            if (p.PropertyType.IsValueType || p.PropertyType == typeof(string) || p.PropertyType == typeof(Nullable<DateTime>) || p.PropertyType == typeof(DateTime))
                            {
                                var c = (prop.GetValue(x) == null) ? string.Empty : prop.GetValue(x).GetType().GetProperty(p.Name).GetValue(prop.GetValue(x));
                                var o = (prop.GetValue(y) == null) ? string.Empty : prop.GetValue(y).GetType().GetProperty(p.Name).GetValue(prop.GetValue(y));

                                if (!Equals(c, o))
                                    modifiedProps.Add(p.Name);
                            }
                        }
                        if (modifiedProps.Count > 0) ChangedProperties.Add(prop.Name, modifiedProps);
                    }
                }

　
                //switch (prop.PropertyType)
                //{
                //    case prop.PropertyType == typeof(string):
                //        var c = GetObjectValue<PEPEntity>(x, prop.Name);
                //        var o = GetObjectValue<PEPEntity>(y, prop.Name);
                //        break;
                //    case prop.GetType() == typeof(Int32):

                //        break;
                //    case prop.GetType() == typeof(ICollection):

                //        break;
                //    case typeof(IList):

                //        break;

                //}

            }
            catch (Exception ex)
            {

            }

            return (ChangedProperties.Count == 0);

        }

        public bool PrimaryPepEquals(PrimaryPepEntity x, PrimaryPepEntity y)
        {
            changedprimaryproperties = new Dictionary<string, string>();
            var Xlist = x;
            var Ylist = y;
            var propList = typeof(PrimaryPepEntity).GetProperties();
          
            var changedprimarypep = new StringBuilder();
            try
            {
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
                                string strskip = "PrimaryPepId,CreatedTS,PepRequestStatusID,ChangeRequestID,PreviousPrimaryPepId";
                                if (!strskip.Contains(p.Name))
                                    changedprimarypep.Append(p.Name + "|");

                            }

                        }
                        //else if (p.Name.Contains("CDDGPrimaryPepAssociatedCountryLobs"))
                        //{
                        //    var Xlistprimarypassociatedlob = p.GetValue(Xlist) as IList;
                        //    var Ylistprimarypassociatedlob = p.GetValue(Ylist) as IList;
                        //    if (Ylistprimarypassociatedlob.Count > 0 && Xlistprimarypassociatedlob != null)
                        //    {
                        //        var strLobs = (Ylistprimarypassociatedlob as IList<PrimaryPepAssociatedCountryLobEntity>).Select(i => i.LobId.ToString()).ToList().Except((Xlistprimarypassociatedlob as IList<PrimaryPepAssociatedCountryLobEntity>).Select(i => i.LobId.ToString()).ToList()).ToList();
                        //        if (strLobs.Count > 0)
                        //            changedprimarypep.Append(p.Name + "|");
                        //    }

                        //}

                        //else if (p.Name.Contains("CDDGPrimaryPepCountryLobs"))
                        //{
                        //    var Xlistprimarypassociatedlob = p.GetValue(Xlist) as IList;
                        //    var Ylistprimarypassociatedlob = p.GetValue(Ylist) as IList;
                        //    if (Ylistprimarypassociatedlob.Count > 0 && Xlistprimarypassociatedlob != null)
                        //    {
                        //        var strLobs = (Ylistprimarypassociatedlob as IList<PrimaryPepCountryLobEntity>).Select(i => i.LobId.ToString()).ToList().Except((Xlistprimarypassociatedlob as IList<PrimaryPepCountryLobEntity>).Select(i => i.LobId.ToString()).ToList()).ToList();
                        //        if (strLobs.Count > 0)
                        //            changedprimarypep.Append(p.Name + "|");
                        //    }

                        //}

                    }

                    if (changedprimarypep != null)
                    {
                        if (changedprimaryproperties.ContainsKey("PrimaryPeps"))
                        {
                            changedprimaryproperties.Remove("PrimaryPeps");
                            changedprimaryproperties.Add("PrimaryPeps", changedprimarypep.ToString());
                        }
                        else
                        {
                            changedprimaryproperties.Add("PrimaryPeps", changedprimarypep.ToString());
                        }

                    }
                }

            }
               catch (Exception ex)
            {

            }

            return (changedprimaryproperties.Count == 0);

        }

　
　
        public int GetHashCode(PEPEntity obj)
        {
            throw new NotImplementedException();
        }

    }
}
