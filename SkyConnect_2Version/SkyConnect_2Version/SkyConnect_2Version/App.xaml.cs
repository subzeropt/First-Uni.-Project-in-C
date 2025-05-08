using Microsoft.AspNetCore.Components.WebView.Maui;
using Microsoft.AspNetCore.Components.WebView.Maui;
using Microsoft.Maui.Controls;
using SkyConnect_2Version.Pages; // ou ajusta conforme o teu namespace real


public App()
{
    InitializeComponent();

    MainPage = new ContentPage
    {
        Content = new BlazorWebView
        {
            HostPage = "wwwroot/index.html",
            Services = MauiProgram.CreateMauiApp().Services,
            RootComponents =
            {
                new RootComponent
                {
                    Selector = "#app",
                    ComponentType = typeof(Weather)
                }
            }
        }
    };
}




