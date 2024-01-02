       
float add_and_multiply(float x, float y);
int nCompletionStatus = 0;
float add(float x, float y)
{
  float z = x + y;
  return z;
}
float add_and_multiply(float x, float y)
{
  float z = add(x,y);
  z *= (3.0);
  return z;
}
extern int nCompletionStatus;
int main(int argc, char* argv[])
{
  float x = 1.0;
  float y = 5.0;
  float z;
  z = add_and_multiply(x,y);
  nCompletionStatus = 1;
  return 0;
}
