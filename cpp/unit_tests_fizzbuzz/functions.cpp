string FizzBuzz(int n){
  if(n>=1){
    if(n%15==0){
      return "FizzBuzz";
    }else if(n%3==0){
      return "Fizz";
    }else if(n%5==0){
      return "Buzz";
    }
  }
}
