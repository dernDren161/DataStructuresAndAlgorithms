
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51


public class MaxVowelsSubstring
{
  static boolean isVowel(char ch)
  {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
  }

  static int maxVowelsInSubstring(String s,int k)
  {
    int countVowels=0;  //Maintains overall count of vowels
    // Count vowels in First Window
    for(int i=0;i<k;i++)
    {
        if(isVowel(s.charAt(i)))
            countVowels++;
    }

    int maxVowels = 0;
    // Update maxVowels for first window.
    if(maxVowels< countVowels)
        maxVowels = countVowels;

    for(int i=k;i<s.length();i++)
    {
        if(isVowel(s.charAt(i)))          // check if current char is a vowel.
            countVowels++;

        if(isVowel(s.charAt(i-k)))      // check if starting of previous window was a vowel
            countVowels--;

        maxVowels = Math.max(maxVowels,countVowels);   // update maxVowels for each window.
    }

    return maxVowels;
  }

  public static void main(String args[])
  {
      String str = "java2blog";
      int k = 3;
      int result = maxVowelsInSubstring(str,k);

      System.out.println("The Maximum Vowels present in the Substring of size "+k+" is : "+result);
  }

}
