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

                if(result.NumSteps != 0)
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
