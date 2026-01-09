# Student Record Manager

A robust C++ command-line application for managing student records. This project allows users to perform CRUD (Create, Read, Update, Delete) operations on student data, ensuring data integrity through input validation and persistent storage in a local text file.

## 🚀 Features

* **Add Student Records**: Create new entries with a unique ID, Name, and CGPA.
* **Persistent Storage**: Automatically saves all records to a `students.txt` file and loads them upon starting the application.
* **Data Validation**:
* Ensures IDs are unique before adding a new record.
* Validates CGPA input to ensure it falls within the 0–10 range.
* Handles invalid non-numeric inputs gracefully to prevent program crashes.


* **Search Functionality**: Quickly find a specific student's details using their unique ID.
* **Record Management**: View a complete list of all registered students or delete specific records by ID.

## 🛠️ Technologies Used

* **Language**: C++.
* **Standard Template Library (STL)**: Utilizes `vector` for data management and `algorithm` (specifically `remove_if`) for efficient deletion.
* **File I/O**: Uses `fstream` for reading from and writing to the local database file.
* **String Manipulation**: Employs `stringstream` for parsing CSV-style data from the storage file.

## 📁 File Structure

* `student.cpp`: Contains the complete source code, including the `Student` class, `StudentManager` logic, and the main menu loop.
* `students.txt`: (Generated automatically) A comma-separated text file used to store student records persistently.

## ⚙️ Installation & Usage

### Prerequisites

* A C++ compiler (e.g., GCC/G++, Clang, or MSVC).

### Compilation

Use the following command to compile the source code:

```bash
g++ student.cpp -o student_manager

```

### Running the Application

Execute the compiled binary:

```bash
./student_manager

```

## 🖥️ How it Works

1. **Menu Interface**: Upon execution, the program presents a numbered menu (1-5) for adding, displaying, searching, deleting, or exiting.
2. **Data Persistence**: When a student is added or deleted, the `saveToFile()` function immediately updates `students.txt`.
3. **Error Handling**: The `safeIntInput` and `safeFloatInput` functions loop until valid data is provided, preventing the application from entering an infinite loop on bad input.
