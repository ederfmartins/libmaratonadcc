bool nextPermutation(string& number)
{
       bool isBigger = true;
       int i, j;

       for (i = number.size() - 1; i >= 0; i--)
       {
               if (number[i] < number[i+1]) break;
       }

       if (i != -1)
       {
               isBigger = false;

               for (j = number.size() - 1; j >= i+1; j--)
               {
                       if (number[j] > number[i])
                       {
                               break;
                       }
               }

               int tmp = number[i];
               number[i] = number[j];
               number[j] = tmp;

               j = number.size() -1;
               i++;

               while (i < j)
               {
                       tmp = number[i];
                       number[i] = number[j];
                       number[j] = tmp;
                       i++;
                       j--;
               }
       }

       return isBigger;
}
