using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using System.Reflection;

namespace monoTestSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Tests t = new Tests();
            t.temp = 234;
            Tests2 t2 = t.GetNewTests2(123);
            Tests2.GetNewTests(out Tests tt);
            Console.WriteLine(tt.temp.ToString() + " " + t.temp);
        }
    }

    [NativeHeader("Tests.h")]
    [NativeClass("Tests")]
    public class Tests
    {
        [NativeMethod("Tests::Tests")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern Tests();
        public extern string GetStringTestProp
        {
            [NativeMethod("Tests::get_GetStringTestProp")]
            [MethodImpl(MethodImplOptions.InternalCall)]
            get;
            [NativeMethod("Tests::set_GetStringTestProp")]
            [MethodImpl(MethodImplOptions.InternalCall)]
            set;
        }
        [NativeMethod("Tests::getNewTests2")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern Tests2 GetNewTests2();
        [NativeMethod("Tests::getNewTests2")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern Tests2 GetNewTests2(int value);
        public int temp = 0;
    }
    [NativeHeader("Tests2.h")]
    [NativeClass("Tests2")]
    public class Tests2
    {
        [NativeMethod("Tests2::Tests2")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern Tests2();
        public extern int GetIntTestProp
        {
            [NativeMethod("Tests2::get_GetIntTestProp")]
            [MethodImpl(MethodImplOptions.InternalCall)]
            get;
            [NativeMethod("Tests2::set_GetIntTestProp")]
            [MethodImpl(MethodImplOptions.InternalCall)]
            set;
        }
        [NativeMethod("Tester::GetNewTests")]
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void GetNewTests(out Tests tests);
    }
    #region NativeAttributes
    public class Native : Attribute 
    { 
        public enum Type
        { 
            Header, 
            Class, 
            Method, 
        } 
        public Type NativeType; 
        public Native(Type nativeType) => NativeType = nativeType;
    }
    public class NativeHeader : Native
    {
        public string Header;
        public NativeHeader(string header) : base(Type.Header) => Header = header;
    }
    public class NativeClass : Native
    {
        public string Class;
        public NativeClass(string @class) : base(Type.Class) => Class = @class;
    }
    public class NativeMethod : Native
    {
        public string Method;
        public NativeMethod(string method) : base(Type.Method) => Method = method;
    }
    #endregion
}
