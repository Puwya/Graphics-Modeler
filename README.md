<div align=center>
     <h1>2D Graphics Modeler</h1>
</div>

## Contributors
| Member            | Roles          | 
|-------------------|----------------|
| Connor Darling    | Product Owner  |
| Carlos Aguilera   | SCRUM Master   |
| Cameron Rosenthal | Team Member    |
| Liam Eastwood     | Team Member    |
| Joesph Bobby      | Team Member    |

<br/>

### IMPORTANT
> Username: admin

> Password: password123

## Overview 
This project models as a library for basic 2D graphical objects.
The goal is to exercise C++ fundamentals to construct this project
such as inheritance, aggregation, polymorphism, exception handling,
templates, operator overloading, and move semantics. There is a 
Shape class interface that allows all other shapes to derive from it.
To store these shapes, a custom vector class is implemented using a
basic iterator member type with `begin()` and `end()` methods.
To sort the vector of shape objects, a custom selection sort algorithm
is implemented using templated functions to compare perimeter and area.

The program is created using the gui library [Qt](https://github.com/qt). Specifically `QPainter` 
and `QWidgets` are used to render shapes and text on the screen. The user
interface is designed to be readable and simple, while still being able to handle
contingencies such as invalid input. In addition to output of text
and shapes in the window, the program allows a user to manipulate size, color,
and location.

Our team has strongly enforced an agile development methodology. These methods include:
- Following a scrum procress of assigning a scrum master, product owner and team member role
- Creating user stories to help with the implementation of features
- Creating UML class diagrams, both use case and state diagrams

## User Interface Design
The following image shows an early design of the graphical user interface. Features include:
- Choose demo shapes using a header pane
- A collapsable side navigation bar to modify any default attribute of a given shape
- Settings header pane for user settings, contact information, and save and exit

<img src="assets/readme-images/EarlyInterfaceDesign.jpeg"
     alt="Early Interface Design"
     width=65% />

## Sprints

  | (Sprint #1) Estimated Time: 3 weeks |
  | :---------------------------------: |
  
- [X] Implement shapes.txt parser object/logic  
- [X] Implement vector container 
- [X] Begin implementation of shape abc interface & inheritance hierarchy (line, polyline ...) 
- [X] Investigate/understand qt qpainter demo project 
- [X] Build basic 2d modeler qt project with login screen 

<br />

  | (Sprint #2) Estimated Time: 3 weeks |
  | :---------------------------------: |
  
- [ ] Complete implementation of shape abc interface & inheritance hierarchy (line, polyline ...)
- [ ] Ability to render 2d shapes (2d modeler qt project)
- [ ] Renderarea widget (inherits from qwidget like qt 2d rendering demo project) can dislpay all geometric shapes
- [ ] Ability to render all shapes from shapes.txt in renderarea widget (2d modeler qt project)
- [ ] Reports to display shapes, shape perimeter & area (2d modeler qt project)
- [ ] Update 2d shapes (i.e. add, remove or move) via rendering widget forms (2d modeler qt project)
- [ ] Persist changes to shapes.txt file

<br />

  | General Requirement List |
  | :---------------------------------: |
  
- [x] Use inheritance
- [X] Use aggregation
- [X] Use exception handling
- [x] Use a virtual function
- [X] Use at least two overload operators
- [X] At least one class using templates
- [X] At least one class must contain a pointer (write copy constructor and test it)
- [X] Invalid inputs should be addressed.
- [ ] Doxygen documentation
- [ ] Valgrind memory leak check
- [ ] Guests should be able to enter "satisfied customer" testimonials that persist between executions.
- [X] Provide "Contact us" method with team name and logo
  
