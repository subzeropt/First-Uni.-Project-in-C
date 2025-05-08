using System;
using System.Threading.Tasks;
using SkyConnect_2Version.Models;
using SkyConnect_2Version.Services;

namespace SkyConnect_2Version.Controllers
{
    public class AppController
    {
        private readonly IAuthService _authService;
        private readonly IWeatherService _weatherService;

        public event Action<User> OnUserAuthenticated;
        public event Action<WeatherForecast> OnWeatherUpdated;

        public AppController(IAuthService authService, IWeatherService weatherService)
        {
            _authService = authService;
            _weatherService = weatherService;
        }

        public bool Login(string username, string password)
        {
            if (_authService.Authenticate(username, password))
            {
                OnUserAuthenticated?.Invoke(new User { Username = username });
                return true;
            }
            return false;
        }

        public async Task<WeatherForecast?> GetWeather(string city)
        {
            var forecast = await _weatherService.GetWeatherAsync(city);
            if (forecast != null)
            {
                OnWeatherUpdated?.Invoke(forecast);
            }
            return forecast;
        }
    }
}


