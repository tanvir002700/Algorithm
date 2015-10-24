The solution consists of constructing the suffix array and then finding the number of distinct substrings based on the Longest Common Prefixes.
One key observation here is that:
If you look through the prefixes of each suffix of a string, you have covered all substrings of that string.

Let us take an example: BANANA
Suffixes are:
0) BANANA
1) ANANA
2) NANA
3) ANA
4) NA
5) A
It would be a lot easier to go through the prefixes if we sort the above set of suffixes, as we can skip the repeated prefixes easily.
Sorted set of suffixes:
5) A
3) ANA
1) ANANA
0) BANANA
4) NA
2) NANA

From now on,
LCP = Longest Common Prefix of 2 strings.
Initialize
ans = length(first suffix) = length("A") = 1.

Now consider the consecutive pairs of suffixes, i.e, [A, ANA], [ANA, ANANA], [ANANA, BANANA], etc. from the above set of sorted suffixes.

We can see that,
LCP("A", "ANA") = "A".
All characters that are not part of the common prefix contribute to a distinct substring. In the above case, they are 'N' and 'A'. So they should be added to ans.
So we have,
1.ans += length("ANA") - LCP("A", "ANA")
2.ans = ans + 3 - 1 = ans + 2 = 3
………………………..
do same thing for other pairs.
