
# Aplikacja Obliczająca Wymiary Schodów

## Opis
Aplikacja napisana w .NET MAUI, służąca do obliczania optymalnych wymiarów schodów na podstawie podanej wysokości i długości schodów. Wynik obliczeń zawiera:
- Liczbę stopni,
- Wysokość pojedynczego stopnia,
- Głębokość pojedynczego stopnia.

## Zrzut ekranu
Ekran aplikacji zawiera pola wprowadzania danych, przycisk do obliczeń oraz etykietę, w której wyświetlany jest wynik.

## Struktura plików
### `MainPage.xaml`
Definiuje interfejs użytkownika z użyciem XAML:
- **`Entry`**: pola do wprowadzania wysokości i długości schodów.
- **`Button`**: przycisk do obliczeń.
- **`Label`**: etykieta wyświetlająca wyniki.

### `MainPage.xaml.cs`
Zawiera logikę obliczeń:
- Obsługa zdarzenia kliknięcia przycisku.
- Algorytm obliczający optymalne wymiary schodów.

## Instalacja i Uruchamianie
1. Otwórz projekt w Visual Studio 2022 (z zainstalowanym .NET MAUI).
2. Skonfiguruj urządzenie docelowe (emulator, urządzenie mobilne lub komputer).
3. Uruchom aplikację (`Run`).

## Logika Obliczeń
1. Wysokość stopni mieści się w zakresie **16-19 cm**.
2. Głębokość stopni mieści się w zakresie **25-32 cm**.
3. Program iteruje przez możliwe wartości wysokości i głębokości stopni, dobierając takie parametry, które maksymalnie wykorzystują długość schodów, jednocześnie minimalizując różnicę pomiędzy długością schodów a faktyczną długością obliczonych stopni.

### Przykład działania:
- **Wysokość schodów**: 300 cm,
- **Długość schodów**: 500 cm.

Wynik:
- Liczba stopni: 17,
- Wysokość stopnia: 17.65 cm,
- Głębokość stopnia: 29.41 cm.

## Kod
### MainPage.xaml
```xml
<ContentPage xmlns="http://schemas.microsoft.com/dotnet/2021/maui"
             xmlns:x="http://schemas.microsoft.com/winfx/2009/xaml"
             x:Class="Sigma.MainPage"
             Title="Schody">

    <ScrollView>
        <VerticalStackLayout
            Padding="20"
            Spacing="10">

            <Label Text="Wysokość Schodów" FontSize="Medium"/>
            <Entry x:Name="StairHeightEntry" Placeholder="Wpisz wysokosc schodow w cm" Keyboard="Numeric"/>

            <Label Text="Długość Schodów" FontSize="Medium"/>
            <Entry x:Name="StairLengthEntry" Placeholder="Wpisz długosc schodow w cm" Keyboard="Numeric"/>

            <Button Text="Oblicz schody" Clicked="OnCalculateClicked"/>

            <Label x:Name="ResultLabel" Text="Wynik" FontSize="Medium"/>

        </VerticalStackLayout>
    </ScrollView>

</ContentPage>
```
namespace Sigma
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
        }

        public void OnCalculateClicked(object sender, EventArgs e)
        {
            if (float.TryParse(StairHeightEntry.Text, out float Sh) && float.TryParse(StairLengthEntry.Text, out float Sl))
            {
                var result = CalculateStairs(Sh, Sl);
                if (result.NumSteps != 0)
                {
                    ResultLabel.Text =
                        $"Liczba stopni: {result.NumSteps}\n" +
                        $"Wysokość stopnia: {result.StepHeight}cm\n" +
                        $"Głębokość stopnia: {result.StepDepth}cm";
                }
                else
                {
                    ResultLabel.Text = "Nie można stworzyć takich schodów";
                }
            }
            else
            {
                ResultLabel.Text = "";
            }
        }

        private StairsResult CalculateStairs(float Sh, float Sl)
        {
            int minHeight = 16;
            int maxHeight = 19;
            int minDepth = 25;
            int maxDepth = 32;
            float checkNumber = 0.01f;
            int bestSteps = 0;
            float bestHeight = 0, bestDepth = 0;
            float minDepthDiff = Sl;

            for (float stepHeight = minHeight; stepHeight <= maxHeight; stepHeight += checkNumber)
            {
                int steps = (int)(Sh / stepHeight) + 1;
                if (Math.Round(steps * stepHeight, 2) == Sh)
                {
                    for (float stepDepth = minDepth; stepDepth <= maxDepth; stepDepth += checkNumber)
                    {
                        float totalDepth = steps * stepDepth;
                        if (Math.Round(totalDepth, 2) <= Sl)
                        {
                            float depthDiff = Sl - totalDepth;
                            if (depthDiff < minDepthDiff)
                            {
                                minDepthDiff = depthDiff;
                                bestSteps = steps;
                                bestHeight = (float)Math.Round(stepHeight, 2);
                                bestDepth = (float)Math.Round(stepDepth, 2);
                            }
                        }
                    }
                }
            }

            return new StairsResult
            {
                NumSteps = bestSteps,
                StepHeight = bestHeight,
                StepDepth = bestDepth
            };
        }

        private struct StairsResult
        {
            public int NumSteps { get; set; }
            public float StepHeight { get; set; }
            public float StepDepth { get; set; }
        }
    }
}
