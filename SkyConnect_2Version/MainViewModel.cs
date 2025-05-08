using System;
using System.Threading.Tasks;
using SkyConnect_2Version.Models;
using SkyConnect_2Version.Controllers;

namespace SkyConnect_2Version.ViewModels
{
    public class MainViewModel
    {
        private readonly AppController _controller;

        public string City { get; set; } = "Lisboa";
        public string Temperature { get; private set; }
        public string Description { get; private set; }
        public bool HasError { get; private set; } = false;

        public event Action StateChanged;

        public MainViewModel(AppController controller)
        {
            _controller = controller;
            _controller.OnUserAuthenticated += user =>
                Console.WriteLine($"Bem-vindo {user.Username}!");
        }

        public bool Login(string username, string password)
        {
            return _controller.Login(username, password);
        }

        public async Task FetchWeather()
        {
            var forecast = await _controller.GetWeather(City);
            if (forecast == null)
            {
                HasError = true;
                Temperature = null;
                Description = null;
            }
            else
            {
                HasError = false;
                City = forecast.City;
                Temperature = forecast.Temperature;
                Description = forecast.Description;
            }

            NotifyStateChanged();
        }

        private void NotifyStateChanged() => StateChanged?.Invoke();
    }
}
