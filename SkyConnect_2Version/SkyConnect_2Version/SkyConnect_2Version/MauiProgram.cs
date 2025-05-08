using Microsoft.Extensions.Logging;
using SkyConnect_2Version.Services;
using SkyConnect_2Version.Controllers;
using SkyConnect_2Version.ViewModels;
using System.Net.Http;

namespace SkyConnect_2Version
{
    public static class MauiProgram
    {
        public static MauiApp CreateMauiApp()
        {
            var builder = MauiApp.CreateBuilder();
            builder
                .UseMauiApp<App>()
                .ConfigureFonts(fonts =>
                {
                    fonts.AddFont("OpenSans-Regular.ttf", "OpenSansRegular");
                });

            builder.Services.AddMauiBlazorWebView();

#if DEBUG
            builder.Services.AddBlazorWebViewDeveloperTools();
            builder.Logging.AddDebug();
#endif

            // ✅ Injeção de dependências para os serviços
            builder.Services.AddHttpClient();
            builder.Services.AddSingleton<IAuthService, AuthService>();
            builder.Services.AddSingleton<IWeatherService, WeatherService>();
            builder.Services.AddSingleton<AppController>();
            builder.Services.AddSingleton<MainViewModel>();

            return builder.Build();
        }
    }
}

