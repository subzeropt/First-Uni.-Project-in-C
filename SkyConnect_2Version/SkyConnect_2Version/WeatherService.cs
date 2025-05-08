using System.Net.Http;
using System.Threading.Tasks;
using Newtonsoft.Json;
using SkyConnect_2Version.Models;

namespace SkyConnect_2Version.Services
{
    public interface IWeatherService
    {
        Task<WeatherForecast?> GetWeatherAsync(string city);
    }

    public class WeatherService : IWeatherService
    {
        private readonly HttpClient _httpClient;

        public WeatherService(HttpClient httpClient)
        {
            _httpClient = httpClient;
        }

        public async Task<WeatherForecast?> GetWeatherAsync(string city)
        {
            try
            {
                var url = $"https://wttr.in/{city}?format=j1";
                var response = await _httpClient.GetStringAsync(url);

                dynamic weatherData = JsonConvert.DeserializeObject(response);

                return new WeatherForecast
                {
                    City = city,
                    Temperature = weatherData.current_condition[0].temp_C + " °C",
                    Description = weatherData.current_condition[0].weatherDesc[0].value
                };
            }
            catch
            {
                return null;
            }
        }
    }
}


/* Nota: Precisas da biblioteca Newtonsoft.Json instalada via NuGet:
Vai a Gerenciador de Pacotes NuGet → procura por Newtonsoft.Json → instala.

Certifica-te de que tens o HttpClient registado no MauiProgram.cs:

csharp
Copy
Edit
builder.Services.AddHttpClient();
builder.Services.AddSingleton<IWeatherService, WeatherService>();
*/
