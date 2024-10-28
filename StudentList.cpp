	#include "StudentList.h"

	// Define a constructor to initialize the list. The list starts with no Students
    StudentList::StudentList() {}
    head = nullptr;  // The list is empty, so head is set to nullptr.
    tail = nullptr;  // The list is empty, so tail is set to nullptr.
    count = 0;  }

	// return the number of students currently in the list
	int StudentList::listSize() {
		return count;
	}

	//add a Node with a student to the front (head) of the list.
	void StudentList::addFront(Student s) {
	 Node* newNode = new Node;   
    newNode->data = s;
    newNode->next = head;
	
	if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        head->prev = newNode;  // Only if it's a doubly linked list
        head = newNode;
    }
    count++;  // Increase the student count
}
}

	//add a Node with a student to the back (tail) of the list.
	void StudentList::addBack(Student s) {
	Node* newNode = new Node;
    newNode->data = s;
    newNode->next = nullptr;}

	if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;  // Only if doubly linked
        tail = newNode;
    }
    count++;  // Increase the student count
}


	//Print out the names of each student in the list.
	void StudentList::printList() { Node* current = head;
    while (current != nullptr) {
        cout << current->data.getName() << endl;  // Assuming Student class has a getName() method
        current = current->next;
    }}

	// Remove the Node with the student at the back (tail) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popBack() {{
    if (tail == nullptr) {  // If the list is empty, print an error message
        cout << "List is empty, cannot pop." << endl;
        return;
		}

	// Remove the Node with the student at the front (head) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popFront() {
		 if (head == nullptr) {
    cout << "Error: Cannot pop from an empty list." << endl;
    return;
  }
  Node *temp = head; 
  head = head->next; 
  if (head == nullptr) { 
    tail = nullptr;
  }
  delete temp;

	}

	//insert a student at the position "index".
	// for this list, count head as index 0
	// if index is outside of current list range, 
	// print a message and insert the student at the back of the list
	// the previous Node at your target index should be moved forward. "For exampe, Node with student at index i, becomes index i+1" 
	// Remember that you already have methods that can add students to the front or back of list if needed! Don't repeat this code.
	void StudentList::insertStudent(Student s, int index) {
    if (index <= 0) { 
        addFront(s); 
        return;
    }

    Node* current = head;
    int currentIndex = 0;

    
    while (current != nullptr && currentIndex < index - 1) {
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr || current->next == nullptr) {
       
        addBack(s); 
    } else {
        
        Node* newNode = new Node(s);
        newNode->next = current->next;
        current->next = newNode;
    }
}


	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and create and return a dummy student object
	Student StudentList::retrieveStudent(int idNum) {
    Node* current = head;

    
    while (current != nullptr) {
        if (current->student.getId() == idNum) { 
            return current->student;
        }
        current = current->next;
    }

    
    cout << "Student with ID " << idNum << " not found. Returning a dummy student.\n";
    return Student();
}


	// Remove a Node with a student from the list with a given id number
	// If no student matches, print a message and do nothing
	void StudentList::removeStudentById(int idNum) {}
if (head == nullptr) return; // Empty list

    // If the student is at the head
    if (head->student.getId() == idNum) { // Assuming getId() returns student's ID
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->student.getId() != idNum) {
        current = current->next;
    }

    if (current->next == nullptr) {
        std::cout << "Student with ID " << idNum << " not found.";
    } else {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}
	
	void StudentList::updateGPA(int idNum, float newGPA) {}
Node* current = head;

    while (current != nullptr) {
        if (current->student.getId() == idNum) { 
            current->student.setGPA(newGPA); 
            return;
        }
        current = current->next;
    }

    std::cout << "Student with ID " << idNum << " not found.\n";
}
	//Add all students from otherList to this list.
	//otherlist should be empty after this operation.
	/*
	For example, if the list has 3 students:
	s1 <-> s2 <-> s3
	and otherList has 2 students
	s4 <-> s5
	then after mergeList the currently list should have all 5 students
	s1 <-> s2 <-> s3 <-> s4 <-> s5
	and otherList should be empty and have zero students.
	*/
	void StudentList::mergeList(StudentList &otherList) {if (index < 0) {
    cout << " Invalid index. Inserting at the back of the list." << endl;
    pushBack(s);
    return;
  }
  if (index == 0) { 
    pushFront(s);
    return;
  }
  int currentIndex = 0;
  Node *current = head;
  while (current != nullptr && currentIndex < index - 1) {
    current = current->next;
    currentIndex++;
  }
  if (current == nullptr) { // If the index is outside the list range
    cout << "Error: Invalid index. Inserting at the back of the list." << endl;
    pushBack(s);
    return;
  }
  Node *newNode = new Node(s);
  newNode->next = current->next; 
  current->next = newNode;
  if (current == tail) { 
    tail = newNode; 
}
}

	//create a StudentList of students whose gpa is at least minGPA.
	//Return this list.  The original (current) list should
	//not be modified (do not remove the students from the original list).
	StudentList StudentList::honorRollList(float minGPA) {
		 StudentList honorRollList;
    Node* current = head;

    while (current != nullptr) {
        if (current->student.getGPA() >= minGPA) { 
            honorRollList.addBack(current->student); 
        }
        current = current->next;
    }

    return honorRollList;
}
