# QUATFUCK

numbers in base 4 + 4 (named I4)
each line is a memory address, you can use space to improve readability.
ascii are converted to ASC4 and put in memory

memory 64k [4-77777777]
memory content is filled with random numbers at the start

### ARITHMETIC

0,1,2,3 - put 0,1,2,3 in memory 
(constant negative numbers, 0 is 0)
negative numbers start with 1|2|3
positives numbers starts with 4|5|6|7
All the math operations are applied to the numbers as decimals. Then, the result is "normalised" to I4.
WIP: Could be the "un-normalised" version useful? Numbers with (8,9) could be something like "exceptional" numbers. 
     Exceptional numbers live only in the registries as a result of operations. They cannot be stored as it is in memory.
WIP: Could be the "half-normalised" number useful? This removes the sign, normalizing only the lower part (1,2,3).

### COMMANDS

N.B. Numbers or memory locations are written in little-endian format!

!@#$ - write in 4 registers resp.

[n]m - repeat m times n

> - increment by 1d a register

< - decrement by 1d a register

>n - copy R3 value in n

<n - copy (n) in R3

\ - swap adjacent registers

\ - conditional (-+=) jump: resp. less than 0, more than 0, equal to 0

/ - jump [memory address in I4 little endian] (unconditional)

/ - divide the supplied register by 4 and normalise the result
    N.B.: the normalised result converges/oscillates to/around a couple of values after a specific amount of passes. 
    TODO: understand if there is an algorithm to identify the number of passes!!!

/' - integer I4 divide (R0/memory location) - R0 get remainder and R1 get quotient

. - print the memory content or registry

, - print the ASC4 value on the screen

} - rotate 1 pos right

{ - rotate 1 pos left

+ - add to registry memory content. store result in the registry.

- - sub to registry memory content. store result in the registry.

~ - randomise! generate an I4 positive number, using as a seed a number (read as a decimal) in memory (a random number). 
    You don't need to do that... but it could be useful someday.

` - stop/end/halt - performs a dump of the first 128 locations of memory. Numbers are displayed in big-endian format.
--- 

ASC4

A    - 654     B    - 444     C    - 476
D    - 655     E    - 445     F    - 477
G    - 656     H    - 446     I    - 544
J    - 657     K    - 447     L    - 545
M    - 664     N    - 454     O    - 546
P    - 665     Q    - 455     R    - 547
S    - 666     T    - 456     U    - 554
V    - 667     X    - 457     Y    - 555
W    - 674     Z    - 464     ![¡] - 556
?    - 675     .[…] - 465     ,[∞] - 557
$[¢] - 676     %    - 466     /[|] - 564
*    - 677     (    - 467     )    - 565
:    - 744     ;    - 474     [    - 566
]    - 745     {[•] - 475     }[·] - 567

---
