using System;

namespace SkyConnect_2Version.Services
{
    public interface IAuthService
    {
        bool Authenticate(string username, string password);
    }

    public class AuthService : IAuthService
    {
        public bool Authenticate(string username, string password)
        {
            return username == "admin" && password == "password";
        }
    }
}
