# SKPokerPython
Python module to use the very fast SKPoker hand evaluator with extra features.  This uses the skpoker C++ programs
made by Kenneth Shackleton (awesome job!) that can be found at https://github.com/kennethshackleton/SKPokerEval

Let's face it, Python is slow.  You need speed to evaluate poker hands, and this repository will help you complete your
poker project in Python, but use to speed of C++ to evaluate the hands.

Installation instructions:
1) Download the entire repository.
2) Open a command line and move to the repository directory.
3) Enter: "python setup.py build" in the command line (without the quotes).
4) There will now be a directory called build in the repository directory.  Go inside it and there should be more
directories.  These will be called different things depending on your operating system.  For me it's called
lib.win32-2.7.  Go into it and find handEvaluatorCPP.pyd.  This is the python library you can use.
5) Copy handEvaluatorCPP.pyd into your python project directory.
6) Use it with a normal import statement:
import handEvaluatorCPP

Use:
1) import handEvaluatorCPP
2) Evaluate a hand by:
handEvaluatorCPP.evaluate([mycard1, mycard2],[boardcard1,boardcard2,boardcard3,boardcard4,boardcard5],[hand_weights])
XcardX is an int [0-51]
hand_weights is an optional 169 element list of lists of floats containing the relative percentage chance that you think the opponent will have
a given hand.

Card values are as follows 0=As, 1=Ah, 2=Ad, 3=Ac, 4=Ks, 5=Kh, 6=Kd, ..., 50=2d, 51=2h. (s = spade, h=heart, d = diamond, c = club).

hand_weights can be confusing.  It is a list of lists.  The first list dimension has 169 elements, corresponding to each
possible hand in Hold'em (AA, AKunsuited, AQunsuited, etc.).  Here are the hands corresponding to each index:
0-12:    AA, AKunsuited, AQunsuited, ... A2unsuited
13-24:   AKsuited-A2suited
25-36:   KK-K2unsuited
37-47:   KQsuited-K2suited
48-58:   QQ-Q2unsuited
59-68:   QJsuited-Q2suited
69-78:   JJ-J2unsuited
79-87:   JT-J2suited
88-96:   TT-T2unsuited
97-104:  T9suited-T2suited
105-112: 99-92unsuited
113-119: 98suited-92suited
120-126: 88-82unsuited
127-132: 87-82suited
133-138: 77-72unsuited
139-143: 76-72suited
144-148: 66-62unsuited
149-152: 65-62suited
153-156: 55-52unsuited
157-159: 54-52suited
160-162: 44-42unsuited
163-164: 43-42suited
165-166: 33-32unsuited
167:     32 suited
168:     22

The second dimension contains the individual card suit information.
For a pocket pair like AA, there are 6 possible combinations (sh, sd, sc, hd, hc, dc).  For a suited pocket hand, there are 4
possible combinations (ss, hh, dd, cc).  For an unsuited pocket hand, there are some caveats.  We will identify
the suit of the largest value card first, and then the suit of the smallest value card.  The ordering of the possible combination
of suits is as follows:
sh=0
sd=1
sc=2
hs=3
hd=4
hc=5
ds=6
dh=7
dc=8
cs=9
ch=10
cd=11
Now we have a way to identify every possible texas holdem hand with the suits taken into account.
Here's an example:
We want the index for the weight for the hand of 4spades, Jhearts:
This is a J4unsuited hand, corresponding to index 76 (J2unsuited is index 78 from the list above, so J3unsuited is 77, and
J4unsuited is 76).  Now we want the index corresponding to heart-spade.  Heart is first because J is larger than 4.
Looking at the list above, we see that hs corresponds to index 3.  So the weight for the 4spade,Jheart hand is found in
hand_weights[76][3].

