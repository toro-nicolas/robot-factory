# 🏭 Robot Factory 🤖

## Table of contents 📑
- [Description](https://github.com/toro-nicolas/robot-factory/blob/main/README.md#description-)
- [Usage](https://github.com/toro-nicolas/robot-factory/blob/main/README.md#usage-%EF%B8%8F)
- [Result](https://github.com/toro-nicolas/robot-factory/blob/main/README.md#result-)
- [Compilation](https://github.com/toro-nicolas/robot-factory/blob/main/README.md#compilation-%EF%B8%8F)
- [Code mandatory](https://github.com/toro-nicolas/robot-factory/blob/main/README.md#code-mandatory-)
- [What's next ?](https://github.com/toro-nicolas/robot-factory/blob/main/README.md#whats-next--)
- [Contributors](https://github.com/toro-nicolas/robot-factory/blob/main/README.md#contributors-)


## Description 📝
The **Robot Factory** is a project carried out by **groups of 2** (see [Contributors](https://github.com/toro-nicolas/robot-factory/blob/main/README.md#contributors-), during our **1st year** in [**EPITECH**](https://www.epitech.eu/) Grand Ecole program.  
Its purpose is to create in [**C**](https://en.wikipedia.org/wiki/C_(programming_language)) a **[machine-language](https://en.wikipedia.org/wiki/Machine_code) converter**.  
The aim is to convert **champions/robots** written in **assembler** into a **machine language**.  
This project is the first part of the [**Corewar**](https://github.com/toro-nicolas/Corewar), another school project aimed at **fighting the champions/robots** created at the **Robot Factory**.


## Usage ⚔️
You can run Robot Factory like this :
```sh
./asm champion/42.s
```

For more information, please see the help section.
```sh
> ./asm -h
USAGE
        ./asm file_name[.s]
DESCRIPTION
        file_name file in assembly language to be converted into file_name.cor, an executable in the Virtual Machine.
```


## Result 🚩
The result of this project is an **perfect Robot Factory**.  
If you discover a **problem** or an **error**, don't hesitate to **create an issue** and **report it** to us as soon as possible.


### my.epitech.eu result

| Category       | Percentage | Numbers of tests |  Crash   |
|----------------|:----------:|:----------------:|:--------:|
| Algorithm app. |    100%    |       5/5        |    No    |
| Data structure |    100%    |       5/5        |    No    |
| Parsing        |    100%    |      18/18       |    No    |
| Robustness     |    100%    |      35/35       |    No    |
| **Results**    |  **100%**  |    **63/63**     |  **No**  |


### Tests and code coverage
To check that our Robot Factory is **perfect**, we've created a **tester**.  
It will **convert many robots/champions** with our robots factory and the reference one and **check if there's a difference**.
To run the tester, execute this command :
```sh
./tester.sh
```

**Unit tests** were performed using [criterion](https://criterion.readthedocs.io/en/master/intro.html).  
In this project, **only** the **library code is covered**.
Unit tests are still to be performed, but a large part of the code is already covered.

You can compile the project and run the unit tests with this command :
```sh
make tests_run
```


## Compilation 🛠️
You can compile the project with this command :
```sh
make
```

If you want clean the project, you can run this command :
```sh
make fclean
```

You can clean and compile the project with ```make re```.  

You can compile the unit tests with this command :
```sh
make unit_tests
```


## Code mandatory 📦
- You'll need to create a branch where you'll push your code. Once you've completed your tasks on this branch, we'll work together to merge it and check that everything works.
- Every function you add must be code-style.
- Before merging, you'll need to check that all unit tests pass by running ```make tests_run```.
- Each commit will contain ```[+]``` or ```[-]``` or ```[~]``` followed by a message
    - ```[+]``` : Add feature
    - ```[-]``` : Delete feature
    - ```[~]``` : Edit feature

**Of course, in exceptional cases, we may depart from these rules.**


## What's next ? 🚀
- Add github actions
- Add a graphic visualisation
- Add a documentation for each function
- Add unit tests on each piece of code


## Contributors 👥
For this project, we were a group of **2 people**. Here are the people in the group:
- [Christophe VANDEVOIR](https://github.com/ItsKarmaOff)
- [Nicolas TORO](https://github.com/toro-nicolas)
