# PokemonBattleGame
Text based Pokemon Battle Game

My program is a text based version of Pokemon Stadium. This idea came around from

the combination of three things:

1. I saw potential in one of the last assignments that created different characters for

a fantasy game.

2. I wanted to make something that would be fun to use and fun to program.

3. E3 starts the day after this project is due, so I wanted to do a game of some sort.

The idea of making Pokemon Stadium met all three of those those things. I could have a

Pokemon Trainer class that would hold info about the trainer and what Pokemon they

were using. I could have a Pokemon class that could be used for all the different

Pokemon. If I wanted to have a special type of Pokemon I could have another class that

inherited the Pokemon class. I could also have a Pokedex class to keep track of what

Pokemon are available. Once a trainer had picked out their Pokemon they could battle

against a CPU trainer, taking turns back and forth, until there was one trainer with no

Pokemon left. Overall it seemed like a fun idea that would provide some challenge to

program and would also cover a large number of requirements.

I planned to create two objects from the Pokemon Trainer class. One would be the

Trainer representing the user while the other would be the CPU based Trainer. Each

class would hold the name of the trainer, the number of Pokemon the trainer has, and the

trainer’s roster of Pokemon. Additionally there would be functions for actions such as

setting and getting variables as well as for searching through the roster of Pokemon.

In actual Pokemon games, each Pokemon has a large number of attributes that need to

be kept track of. For simplicity in my program I decided to keep track of just the

Pokemon’s name, its type, its HP (Hit Points), and each of the four moves it might use in

battle. Each of the four moves are actually structs because there are a number of

variables associated with each move. Each MoveSet struct keeps track of the name of

the move, the type of move it is, the power of the move, the PP (Power Points) remaining

for the move, and the PP total. For those who don’t know, PP are required for a Pokemon

to perform a move. If the PP for a certain move is 0, then the Pokemon cannot use that

move any more. Generally the more powerful a move is the less PP it has.

The Pokedex class keeps track of the Pokemon available. Each Pokemon has to be hard

coded into the game (there’s no such thing as a create your own Pokemon, so it would

not make sense to allow the user to enter this info within the game itself without having it

already hard coded in to verify that what the user has entered is actually a Pokemon).

This game is about battling Pokemon, not catching Pokemon, so the Pokedex just needs

to be available for reference. Fortunately, it is extremely easy for any programmer to add

additional Pokemon. As you will see when you look at the pokedex.cpp file all the

Pokemon info is neatly organized and ordered. There are also easy to follow instructions

for adding more Pokemon. All the Pokemon are kept in a vector so that it can be

automatically resized when a new one is added by using the push_back command. If

they were kept in an array then the programmer would have to remember to change the

code for the size of the array and renumber each element every time another Pokemon

was added.

Finally there is a Battle Arena class that handles battle operations. The user takes a turn

(which can either involve attacking the other Pokemon or switching to a different

Pokemon) then the CPU takes a turn. The battle ends whenever one of the trainers has

no more Pokemon to put into play.

Requirements

● Demonstrates simple output (cout or printf is fine)

My program uses cout numerous times throughout the program to print out

information to the user. The first instance of cout can be found in my main

pokemonstadium.cpp.

● Demonstrates simple input (cin or getline are fine, better would be to use both :)! )

My program uses cin numerous times throughout the program to accept input

from the user. The first instance of cin can be found in my main

pokemonstadium.cpp file.

● Demonstrates explicit type casting

One of the options in the secret bonus menu (see Requirement 19. Command

Line Arguments for an explanation) is a mutliDemo function in the Bonus class

whose sole purpose is to demonstrate scope and type casting. For the type

casting I have a double f that is equal to 55.5. I print it out once as a double then I

print it out again casted as an int. It prints out 55. The code for the type casting

portion of the function is seen below:

double f = 55.5;

std::cout << "Value of double f: " << f << std::endl;

std::cout << "Value of f after casting from double to int: " << (int) f << std::endl; // casting to type int

● Demonstrates conditional

My program uses if, else if, else statements throughout the program, such as

when asking the user what they would like to do. An example of this is below from

the beginning of my main pokemonstadium.cpp, where the user is asked if they

would like to import a Trainer Profile or create a new one.

if (decision == 'I')

{

}

else

{

}

importTrainerProfile(pokedex, name, numPokemon, selection, pokemonRoster);

createNewProfile(pokedex, name, numPokemon, selection, pokemonRoster);

● Demonstrates logical or bitwise operator (more specifically &, |, ^, &&, ||, !, ==),

Operators are used numerous times throughout the program, especially in

conjunction with while loops. A common usage in my program was when verifying

user input, such as seen below. This code, from pokemonstadium.cpp, followed

the if­else statement code shown above in 4. This loop would continue while the

input was not a char OR (‘||’) while the input was not the letter ‘I’ AND (&&) also

not the letter ‘N’.

while (std::cin.fail() || (decision != 'I' && decision != 'N'))

{

std::cin.clear();

std::cin.ignore(100, ‘\n’);

std::cout << "Your input was invalid.

\nPlease enter either 'I' to import a profile or 'N' to create a new one"

<< std::endl;

std::cin >> decision;

decision = toupper(decision);

}

● Demonstrates at least one loop

Both for and while loops were used throughout my program. An example of a while

loop can be seen in the sample code demonstrated in requirement 5 above.

● Demonstrates at least one random number

Random numbers were utilized to randomly select Pokemon and to make

decisions for the computer controlled rival Pokemon Trainer. The first such

instance of a random number can be found in my main pokemonstadium.cpp file

in the function randomlyPickPokemon. The entire function can also be seen

below:

void randomlyPickPokemon(Pokedex pokedex, const int &numPokemon, std::vector<Pokemon>

&pokemonRoster)

{

srand (time(NULL));

for (int i = 0; i < numPokemon; i++)

{

int selection = rand() % pokedex.getSize();

pokemonRoster.push_back(pokedex.getPokemon(selection));

}

}

● Demonstrates understanding of the three general error categories we talked about

(syntax, logic, and run­time)

It’s hard to demonstrate errors in working code (for hopefully obvious reasons), so

I will talk about the three types of issues instead. There are three main types of

errors: syntax errors, logic errors, and run­time errors.

Syntax errors are errors in coding (such as missing a semicolon, trying to use

something that hasn’t been declared yet, etc). Fortunately these types of errors

are usually caught when the program is compiled so they are often the simplest

and easiest to fix (though sometimes the error messages can be rather cryptic as

to what is wrong). During the development of this program there were many

instances of syntax errors as might be expected while developing a large

program.

Logic errors are errors that cause unexpected behavior. These errors are not

caught by the compiler because there is nothing wrong with the code, beyond it

causing unexpected behavior. These errors are generally noticed when the

program is running and the program behaves in an unexpected way. They will

only be found by either carefully double checking the code or observing the

program and noting when it behaves in an unintended manner. These can

sometimes be easy to figure out and fix (such as if two numbers were added

instead of subtracted or a > was used instead of an <) or they can be rather

difficult to figure out and require a lot of time to fix (perhaps because the

underlying algorithm is flawed).

Run­time errors are errors that occur due to conditions when the program runs.

However, unlike logic errors, these errors often cause the program to crash

instead of causing the program to act erratically. An example of this type of error

is if the program tries to open or write to a file that doesn’t exist. These errors can

also vary from being easy to find and fix to being rather difficult to find and fix.

Often they can be avoided with careful error handling,

● Demonstrates some form of debugging "tricks" that we have learned throughout the

class

One of the most common debugging tricks I use is for verifying user input. As an

example I will show the code below for one such implementation that is found in

the bonus.cpp. In the bonus.cpp file I presented the user with a menu of four

options. To select one of the options the user should enter an int of either 1, 2, 3,

or 4. If the user does this, then the program skips the while look underneath the

input and carries on with the program. However, if the user does not enter correct

input then one of the conditions of the while loop is triggered and the program

enters the while loop. It may be triggered because the int entered was not one of

the four options (above 4, “selection > 4”, or below 1, “selection < 1”). It may also

be triggered because the input did not match the type it was being assigned to.

This situation would be caught by std::cin.fail() which would return true if the input

was not, in this case, an int. For example, if I entered the letter ‘a’ or the word

“hello” instead of an int, std::cin.fail() would trigger true because it recognized that

the program was trying to assign a char or string to an int.

std::cout << "\nPlease enter the number of your selection now: ";

std::cin >> selection;

while (std::cin.fail() || selection > 4 || selection < 1)

{

std::cin.clear();

std::cin.ignore(100, '\n');

std::cout << "That was not a valid selection. Please try again: ";

std::cin >> selection;

}

Though they have since been deleted, while testing my program I constantly used

print statements so I could verify that the program was progressing and easily

identify any bugs if a certain print statement was not reached.

● Demonstrates at least one function that you define

My program uses numerous functions throughout. The first such instance of a

function can be found in my main pokemonstadium.cpp file called

importTrainerProfile. The function declaration for this function can be found in the

same file near the top.

● Demonstrates general functional decomposition to reduce how large a single section of

code is or to make the plan or algorithm obvious for your program

I use a number of functions that perform small parts of the main program. If you

look at my main function in pokemonstadium.cpp, you will see that when setting

up Trainer Profiles I make calls to functions importTrainerProfile,

createNewProfile, and createRivalProfile. Then during battle I use a loop and

include repeated calls to other functions that handle parts of the battle operations.

● Demonstrates how scope of variables works

One of the options in the secret bonus menu (see Requirement 19. Command

Line Arguments for an explanation) is a mutliDemo function in the Bonus class

whose sole purpose is to demonstrate scope and type casting. At the start of the

function an int e is declared and set equal to 0. Next inside a for loop an int e is

declared and set equal to 2. Inside that for loop there is an if statement where an

int e is declared and set equal to 5. The print statement inside the if statement

prints e as equal to 5. The print statement after the if statement, but inside the for

loop prints e as equal to 2. The last print statement outside the for loop prints e as

equal to 0. This shows how the respective values for e are only accessible within

the block of code in which e was defined. The code for the scope portion of the

function is shown below:

void Bonus::multiDemo()

{

int e = 0;

for (int i = 0; i < 5; i++)

{

int e = 2;

if (i == 3)

{

}

std::cout << "e­for:" << e << std::endl; // prints "e­for: 2"

}

std::cout << "e­end:" << e << std::endl; // prints "e­end: 0"

int e = 5; // this e is not accessible outside of the if statement

std::cout << "e­if:" << e << std::endl; // prints "e­if: 5"

}

● Demonstrates the different passing mechanisms

In my program I pass values to functions using both pass­by­value and

pass­by­reference. This can be seen with any of my function declarations that

include arguments.

● Demonstrates function overloading

An instance of function overloading can be found in my pokemonTrainer.cpp file.

There are two functions called getPokemon that return an object of Pokemon

type. One of the function takes an int and returns the Pokemon at the ith place in

the roster, while the other takes in a string and returns the Pokemon whose name

matches the input. The two functions can be found in pokemonTrainer.cpp start.

They can also be seen below:

// Finds the Pokemon by provided or randomly generated int

Pokemon PokemonTrainer::getPokemon(int i)

{

}

// Finds the Pokemon by name and returns the corresponding Pokemon object

Pokemon PokemonTrainer::getPokemon(std::string name)

{

return pokemonRoster[i];

for (int i = 0; i < getNumPokemon(); i++)

{

if (pokemonRoster[i].getName() == name)

{

}

}

return pokemonRoster[i];

}

● Demonstrates at least one string variable (std::string or c­style string)

String variables are used throughout my program. The first instance of an

std::string can be found in my main pokemonstadium.cpp, where a string variable

is created to store the name of the user.

● Demonstrates some form of recursion

One of the options in the secret bonus menu (see Requirement 19. Command

Line Arguments for an explanation) is the ability to play Pokemon Porygon’s

favorite game. Porygon loves calculating Fibonacci numbers. If you enter an int n,

Porygon will calculate the nth Fibonacci number using a recursive function. This

function can be found in the bonus.cpp file and also below:

int Bonus::findPorygonsNumber(int n)

{

if (n == 1 || n == 2) // if n is equal to 1 or 2, return 1

{

return 1;

}

else // otherwise return sum of fibonacci(n­1) + fibonacci(n­2)

{

return findPorygonsNumber(n­1) + findPorygonsNumber(n­2);

}

}

● Demonstrates at least one multi­dimensional array / Demonstrates at least one

dynamically declared array

I was able to demonstrate both Requirement #17 and Requirement #18 in one

example. In one of my additional bonus programs found in the secret bonus menu

(see Requirement 19. Command Line Arguments for an explanation) I used a

dynamic multi­dimensional array to create a Generation I Pokemon Type Chart.

The Type Chart shows the modifiers that are applied to different moves based on

their type. For example, as can be seen in the a fire type attack would cause 2x

the damage against a grass type Pokemon, while a water type attack would only

cause 1⁄2x the damage against a grass type Pokemon. The initialization of this

array is performed in the constructor of the Bonus class. The code of this can be

seen below:

Bonus::Bonus()

{

typeChart = new std::string*[SIZE]; // intializes the array of Pokemon types

for (int i = 0; i < SIZE; i++)

{

typeChart[i] = new std::string[16];

}

}

Please note that the chart is wide so it may not display correctly if your screen is

not set to display enough characters across.

● Demonstrates at least one command line argument

Beyond the core program of Pokemon Stadium, there is also a secret menu with

additional Pokemon programs that can be run. In the spirit of cheat codes and

hidden menus, the secret menu and other programs can only be accessed by

entering a secret word as a command line argument. The secret word is the

answer to a riddle provided at the end of the uploaded Pokemon Stadium

Instruction Manual. If you want to try to solve the riddle yourself, go to the end of

the instruction manual. Otherwise take a look below.

The answer to the riddle is “MISSINGNO.” (all caps, no quotes, with the period at

the end). Enter this as a command line argument and you will be presented with a

secret menu of other programs to run that demonstrate additional requirements

listed here that are not seen in the main Pokemon Stadium program.

● Demonstrates definition and use for at least one struct

A struct is used for the Moveset of each Pokemon. Each move has a name, a

type, a power value, PP (Power Points) remaining, and PP total. The definition of

this struct can be found in pokemon.h and can also be seen below:

struct MoveSet // each Pokemon move consists of...

{

std::string name; // a name

std::string type; // a type

int power; // power

int ppRemaining; // PP (Power Points) remaining

int ppTotal; // PP (Power Points) total

};

Each move struct is given its initial value via the constructor and various other

functions can access and change values of the struct.

● Demonstrates definition and use for at least one class and object

My program uses several classes. The first instance of a class object can be

found in my main pokemonstadium.cpp file where I create an object of the

Pokedex class. Several other class objects are created in the next few lines and

can also be seen below:

Pokedex pokedex; // Pokedex object

PokemonTrainer Red; // Trainer object representing the user

PokemonTrainer Blue; // Trainer object representing the CPU

BattleArena battlearena; // battle arena object where battle functions are handled

Bonus bonus; // bonus object where bonus functions can be found

● Attempts to demonstrate a pointer to an array

In one of my additional bonus programs found in the secret bonus menu (see

Requirement 19. Command Line Arguments for an explanation) I created a small

pointers demo that uses a pointer to an array, prints out the array using the

pointer, and makes changes to the array using the pointer. The function,

pointerDemo, is found in the Bonus class (bonus.cpp). The function can also be

seen below:

void Bonus::pointersDemo()

{

int size = 10;

int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // array of numbers 1­10

int *p = array; // pointer to array

for (int i = 0; i < size; i++) // prints out "1, 2, 3, 4, 5, 6, 7, 8, 9, 10"

{

std::cout << *(p+i) << " ";

}

std::cout << std::endl;

for (int i = 0; i < size; i++) // prints out "1, 2, 3, 4, 5, 6, 7, 8, 9, 10"

{

std::cout << p[i] << " ";

}

std::cout << std::endl;

p[0] = 10; // change first value to 10

p[1] = 9; // change second value to 9

*(p+2) = 8; // change third value to 8

*(p+3) = 7; // change fourth value to 7

p[4] = 6; // change fifth value to 6

for (int i = 0; i < size; i++) // prints out "10, 9, 8, 7, 6, 6, 7, 8, 9, 10"

{

std::cout << p[i] << " ";

}

std::cout << std::endl;

// size of array

}

● Demonstrates at least one custom namespace

In my program I have a namespace called PocketMonsters (the original

Japanese title of Pokemon). Included in the namespace are the two Pokemon

classes Pokemon and Legendary.

● Demonstrates at least one header file you write

Each of the .cpp files (except the main pokemonstadium.cpp) has a

corresponding header file. These can be viewed in the uploaded code files.

● Demonstrates at least one makefile that we use to compile the project on flip

A separate makefile was created (makefile.txt). It could be used with the

command “make ­f makefile.txt”. The complete contents of the makefile can be

seen below:

CXX = g++

CXXFLAGS = ­std=c++0x

CXXFLAGS += ­Wall

CXXFLAGS += ­pedantic­errors

CXXFLAGS += ­g

LDFLAGS = ­lboost_date_time

OBJS = pokemonstadium.o battlearena.o bonus.o pokedex.o pokemon.o pokemontrainer.o

SRCS = pokemonstadium.cpp battlearena.cpp bonus.cpp pokedex.cpp pokemon.cpp

pokemontrainer.cpp

HEADERS = battlearena.h bonus.h pokedex.h pokemon.h pokemontrainer.h

pokemonstadium: ${OBJS} ${HEADERS}

${OBJS}: ${SRCS}

${CXX} ${LDFLAGS} ${OBJS} ­o pokemonstadium

${CXX} ${CXXFLAGS} ­c $(@:.o=.cpp)

● Demonstrates at least one vector

I used several vectors in my program to keep track of Pokemon. The first

instance of a vector can be seen in my main pokemonstadium.cpp. This first

vector is the roster of Pokemon that the user will bring into battle. As the user

selects Pokemon, they are added to the vector using push_back. During battle, if

a Pokemon faints, then that Pokemon is removed using erase (performed in the

removePokemon function found in pokemonTrainer.cpp).

● Demonstrates at least one default constructor, a copy constructor, and a destructor for a

class

Each of my classes implements the constructor variations (constructor,

destructor, etc).

● Demonstrates some form of file IO

At the start of the program the user is given the option of creating a trainer profile

by either importing a text file or creating one from scratch. If the user elects to

import a text file they type in the name of the file they would like to import. If the

user mistypes the name of the file or the file is not found, the user is allowed to

retype the name of the file (instead of the program crashing). The code for this is

found in the importTrainerProfile function in my main pokemonstadium.cpp file.

● Demonstrates inheritance

10

All of the available Pokemon to battle with are regular Pokemon, except for one.

That one is the legendary Pokemon Mewtwo! Mewtwo is based off of an inherited

class of regular Pokemon called Legendary.

● Demonstrates exceptions

In most of my program I tried to handle any possible errors in ways that would

allow the user to fix their mistake (such as if the user mistypes the name of the

text file to import a Trainer File, the program realizes this and allows the user to

retype the file name). So to demonstrate exceptions I created another bonus

program that can be accessed via the secret menu (see Requirement 19.

Command Line Arguments for an explanation). This program is called the

Magikarp Experience, where you get to experience first hand what it is like to be

Magikarp in battle. Magikarp is famous for only having a splash move that does no

damage to an opponent. In the Magikarp Experience, the user takes the role of

Magikarp and is presented with two possible moves: 1) Splash 2) Something

Else. Choosing “Splash” will make Magikarp splash to no effect. If the user

chooses “Something Else” then an exception is thrown because Magikarp knows

nothing else! The function, magikarpExperience, can be found in the Bonus

class. The try­catch block from that function can be seen below:

try

{

if (choice == 1)

{

}

else

{

}

}

catch (std::string e)

{

std::cout << e << std::endl;

std::cout << "Now you know what it is like to be Magikarp!" << std::endl;

break;

}

std::cout << "\nMagikarp used splash!" << std::endl;

std::cout << "No effect!\n" << std::endl;

std::string e = "\nERROR: Magikarp knows nothing else!\n";

throw e;

● (extra credit) Do something awesome perhaps a game, a text editor, a spreadsheet

editor

The core of my program is a game. It is a text based version of Pokemon

Stadium. The user can choose up to six Pokemon and then battle them in arena

against an opponent. The program keeps track of the health of each Pokemon as

well as the remaining moves the Pokemon can take. Users can also switch

Pokemon while in battle.

11

● (extra credit) Can you think of something else that would be good for extra credit, then list

it with a comment and we will consider it :)!

In the original generation of Pokemon there were 151 different creatures. In my

program you can choose from a limited selection of those original 151 (as actually

implementing all 151 would take some time and add no further value to

demonstrating C++ knowledge). However, if my program does not use a

Pokemon that you would really like to use, it is very simply to add more Pokemon!

In pokedex.cpp there is a function, bootup, that creates a vector of all the

available Pokemon programmed into the game. Adding another Pokemon is as

simple as typing in the respective info for the Pokemon you want to add and then

typing in pokedex.push_back(PokemonName). Then the next time the program

starts and the Pokedex is booted up, that Pokemon is now available for use. More

specific details of what to do are explained in bootUp function of pokedex.cpp.

It was already explained in its respective section but I liked using the command

line argument not as part of the regular program progression (like if you use a

cma to enter your name then the program won’t start by asking your name), but

rather as like a cheat code where entering the correct secret word brings you to a

whole other menu of game options that isn’t accessible any other way.

Also, though not related to coding, there is a brief instruction manual included as

well (all video games need one!).

Reflection

This was a challenging project for two reasons. The first reason was that this program was

larger and more complex than anything I’ve programmed before (but this also made it a fun and

exciting learning experience). The second reason was that finding a reason to use 37 different

requirements in a single program was a big challenge in itself (and a source of great frustration

and annoyance). Fortunately I got through it all with a program that I am happy with. As with any

program done quickly in a short amount of time (especially one done while having to study and

take other final exams) there are things in the design that I would love to add or change. There

are also a number of things I would do differently in the future if I were doing this same program

again because of things I learned while doing this program. But overall I am happy with my

program. It was the biggest and best example yet of really seeing how breaking down a

seemingly complex program into easily manageable chunks (one class for Pokemon Trainers,

another class for Pokemon, etc.) can make even large complex programs easier to code and

design. Over the course of this program and the semester as a whole I have really come to

appreciate how a well developed plan can make things go much smoother and quicker in the

long run. The temptation is to always jump in and start coding everything, but things really do

12

work out better when you take a moment to plan. That’s probably the most significant thing I

learned this semester (outside of actual coding syntax).

Files

Text Files CPP Files Header Files

makefile.txt (makefile) pokemonstadium.cpp (main)

TrainerProfile1.txt

(sample import file)

pokedex.cpp pokedex.h

pokemon.cpp pokemon.h

pokemontrainer.cpp pokemontrainer.h

legendary.cpp legendary.h

bonus.cpp bonus.h
