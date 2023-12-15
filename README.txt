# QUATFUCK

numbers in base 4 + 4 (named I4)
each line is a memory address, but you can use space, so each space define a new memory location
ascii are converted to ASC4 and put in memory

memory 64k [4-77777777]
memory content is filled with random numbers at the start

0,1,2,3 - put 0,1,2,3 in memory 
(constant negative numbers, 0 is 0)
negative numbers starts with 1|2|3
positives numbers starts with 4|5|6|7


!@#$ - write in 4 registers resp.
[n]m - repeat m times n
> - increment a register
< - decrement a register
m>n - copy (m) in n
m<n - copy (n) in m
\ - swap registers
/ - jump
/ - divide register by 4
. - print the memory content
, - print the ASC4 value on the screen
} - rotate 1 pos right
{ - rotate 1 pos left
+ - add to registry memory content
- - sub to registry memory content
~ - randomize! generate a I4 positive number, using as a seed a number (read as a decimal) in memory (it's a random number too). 
You don't really need to do that... but it could be useful someday.
` - stop/end/halt
--- 

ASC4

A - 654     B - 444     C - 476
D - 655     E - 445     F - 477
G - 656     H - 446     I - 544
J - 657     K - 447     L - 545
M - 664     N - 454     O - 546
P - 665     Q - 455     R - 547
S - 666     T - 456     U - 554
V - 667     X - 457     Y - 555
W - 674     Z - 464     ! - 556
? - 675     . - 465     , - 557
$ - 676     % - 466     / - 564
* - 677     ( - 467     ) - 565
: - 744     ; - 474     [ - 566
] - 745     { - 475     } - 567

---
