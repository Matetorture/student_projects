using Microsoft.Maui.Graphics;
namespace MauiApp1
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
            StairsCanvas.Drawable = new StairsDrawable();
        }

        public void OnCalculateClicked(object sender, EventArgs e)
        {
            if(float.TryParse(StairHeightEntry.Text, out float Sh) && float.TryParse(StairLengthEntry.Text, out float Sl))
            {
                var result = CalculateStairs(Sh, Sl);

                ResultLabel.Text = 
                    $"Liczba stopni: {result.NumSteps}\n" +
                    $"Wysokość stopnia: {result.StepHeight}\n" +
                    $"Głębokość stopnia: {result.StepDepth}";

                ((StairsDrawable)StairsCanvas.Drawable).UpdateStairs(result);
                StairsCanvas.Invalidate();
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

        private class StairsDrawable : IDrawable
        {
            private StairsResult _stairs;

            public void UpdateStairs(StairsResult stairs)
            {
                _stairs = stairs;
            }

            public void Draw(ICanvas canvas, RectF dirtyRect)
            {
                canvas.FillColor = Colors.LightGray;
                canvas.FillRectangle(dirtyRect);

                if (_stairs.NumSteps == 0)
                    return;

                float stepHeight = _stairs.StepHeight;
                float stepDepth = _stairs.StepDepth;
                int steps = _stairs.NumSteps;

                float canvasWidth = dirtyRect.Width;
                float canvasHeight = dirtyRect.Height;

                float scale = Math.Min(canvasWidth / (steps * stepDepth), canvasHeight / (_stairs.NumSteps * stepHeight));

                float x = 0, y = canvasHeight;

                for (int i = 0; i < steps; i++)
                {
                    float scaledStepDepth = stepDepth * scale;
                    float scaledStepHeight = stepHeight * scale;

                    // Draw each step
                    canvas.StrokeColor = Colors.Black;
                    canvas.StrokeSize = 2;

                    canvas.DrawLine(x, y, x + scaledStepDepth, y); // bottom line
                    canvas.DrawLine(x + scaledStepDepth, y, x + scaledStepDepth, y - scaledStepHeight); // vertical line

                    y -= scaledStepHeight;
                    x += scaledStepDepth;
                }
            }
        }
    }

}
