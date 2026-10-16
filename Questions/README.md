# Theorical questions

[Back to main README](../README.md)

1. What are the steps involved in the compilation process?

first, replace all the const_expr with the actual value \
then ressolve the includes, creating a big .i file\
finaly traduction the file into machine language (assembly)


2. What is the difference between a declaration and a definition?

a declaration is to give the signiature of a function (name and parameters), \
a definition is the use of the function, describing its behaviour

3. What is the difference between passing a parameter by value, by reference, and by pointer?

passing a parameter by value will create a copy of the given parameter, meaning you cant modify directly the vakue of the original variable \
passing a parameter by reference mean giving the original variable, without making a copy of it . it cant be null\
passing a parameter by pointer mean giving to the function the memory adress of the variable, il does not do a copy of it but the value a the given adress can be wrong or null

4. What is the difference between the stack and the heap?

the stack is the memory allocated to the app at the compilation time , it reserve a space for the varables that exist at that time. it is continuous in memory and will grow and shrink giving the circomstences (like an accordion)\
the heap is dynamically allocated during the runtime when a "new" variable is created, it is not continuous in memory.

5. What is the difference between struct and class in C++?

in a struct, all the variables are public by default, in a class they are private

6. What is the difference between the public, protected, and private access specifiers?

public mean every class can access its value\
protected mean only a child of the class can access its value\
private mean you can only access it inside of the class

7. What is a pure virtual function? What effect does it have on a class?

a pure virtual function does not have a definition , only a declaration, it turn the class into an interface that can not be instantiated

8. Briefly explain the diamond problem in multiple inheritance.

the diamond probleme is when a class has two parents that themselves have the same parent

9. Name the different containers studied in class and describe the strengths and weaknesses of each.

- array : static size, continuous in memory making it fast to count , iterate and research by index but O(n) to search by exemple
- Vector : dynamic size, continuous in memory, fast to count , interate and research. problem : when inserting , if its size become greater than the allocated one , it must copy all of its elements to another place, that is really expensive, also when destroying one of its element , you have to copy all of the following ones to make it continuous back
- map (unordered) or Hashset : dynamic size, not continuous in memory, O(1) on the reasearch and insertion but slow to count or iterate
- list : dynamic size, not continuous in memory, slow to count and iterate but really fast on insertion and destruction

10. For each of the following scenarios, identify the most appropriate container and justify your choice.
- You need to store the top ten scores in a game. The number of elements is known and will never change.

array because the number is known at the compilation time, its easy to sort and simply the most efficient one

- You need to manage a queue of tasks that must be executed in the order they arrive.

a queue because the first task must be executed first then taken out of the list (FIFO)

- You frequently need to insert and remove elements in the middle of a sequence.

list because its fast to insert and delete elements, just change the pointer on the privious node of the list

- You need to store a large number of elements and frequently check whether a particular element exists. The order of the elements does not matter.

a hashset because of its efficiency of research, giving its hashset method.

- You need to keep track of actions so that the most recent action can be undone before earlier actions.

a stack, becaus you can add action to it and easily acess the last one you added to undo it (FILO)

- You need to manage a collection of players whose number can change over time, with frequent read and traversal operations.

a vector, i need the dynamic size to add or remove players from the list because of a deconnection for exemple, i can also reserve a certain amount of element so that the reallocation doesn't happen too frequently (if the max number of player is known for instance). and the iterations over each elements is fast

- You need to associate each student ID with a grade and retrieve a grade quickly using the student ID.

a map, because each ID is unique so it will easily and rapidly lead to the researched student