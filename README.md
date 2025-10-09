# Infinity Mario Game

This is a final project of the Programming 2 subject from the Computer Engineering Degree (CED) of FIB, UPC.

They told us to do a game based on some code they gave us. The code they gave was just a basic Mario with 3 platforms; we had just the visual generator environment.
I designed a game that can be played endlessly. It has a random object generation, but respecting playable limits, it also has an autodestroying system so memory doesn't get full.
I designed the animations and the mechanics that make it fun: when you play, you become a Mario who is pursuing CED at FIB. You must collect coding files and use them to avoid _Judge_ detonating its bombs, and you must avoid its hummers. The winner is the one who collected more coding files. Randomness and skill may accompany you.
To do all of this, I designed a data structure based on a quaternary tree that manages to reduce the time to find the elements that collide with Mario.


About _Jutge_: At FIB there is software that corrects our codes similarly to LeetCode; it judges them, giving us scores. That's why he uses a Hummer, the game Hummer. But when our code is too slow, has an infinity loop, or has an invalid memory reference... it shows us a bomb. He is telling us that the computer would explode if we tried to execute our program; this is the bomb that Mario deactivates.

To play the game: download the repository, decompress it, open the folder Mario_infinity_game at the terminal, type ```make```, and run ```./mario_pro_2```. Play with `w`, `a`, `d` to jump, move forward, and move backward, respectively.

To add your score: Commit a change directly to classification.txt

***NOT COMPILING???*** Don't panic; there are some compatibilities that you must check. I don't know which will crash in your case, but in mine, VSCode compiled, but the normal terminal didn't. It was because my VSCode has access to more libraries, specifically XKBlib.h. Just install the ones you don't have, or maybe try compiling from VSCode. **If you just want to play**, you can try executing ./mario_pro_2 in the main folder repository so you don't need to deal with compatibilities; this is the executable.
