# Project Manager CLI

**Help you to organize your Projects Directory**

## Overview

The Project Manager CLI is a powerful tool designed to help you efficiently manage your project directories. Whether you need to create, delete, mark, or open projects, this command-line interface provides simple and intuitive commands to streamline your workflow.

## Installation

1. **Clone the repository:**
    ```bash
    git clone https://github.com/your_username/project-manager-cli.git
    ```

2. **Navigate to the project directory:**
    ```bash
    cd project-manager-cli
    ```

3. **Set up the environment variable:**

    - Locate the project files in your OneDrive Documents folder:  
      `%userprofile%\OneDrive\Documents\PMC`

    - Add this path to your system's environment variables:
      - **Windows:**
        1. Open Control Panel.
        2. Go to System and Security > System.
        3. Click on "Advanced system settings" on the left panel.
        4. In the System Properties window, click on the "Environment Variables" button.
        5. Under System Variables, find the "Path" variable and click on Edit.
        6. Add the path `%userprofile%\OneDrive\Documents\PMC` to the list of paths. Click OK to save.

### or

1. **Install in Release:**

    Download it on Release tab 
    Click here to [Download](https://github.com/IzanamiiDevv/PMC/releases/)

2. **Extract the zip file**

    - Go to Downloads and Extract the zip file
    - Open it and copy the Folder Inside
    - Paste it in OneDrive Document

3. **Set up the environment variable:**

    - Locate the project files in your OneDrive Documents folder:  
      `%userprofile%\OneDrive\Documents\PMC`

    - Add this path to your system's environment variables:
      - **Windows:**
        1. Open Control Panel.
        2. Go to System and Security > System.
        3. Click on "Advanced system settings" on the left panel.
        4. In the System Properties window, click on the "Environment Variables" button.
        5. Under System Variables, find the "Path" variable and click on Edit.
        6. Add the path `%userprofile%\OneDrive\Documents\PMC` to the list of paths. Click OK to save.


## Usage

For usage instructions and available commands, refer to the [Project Commands](#Commands:) section in the README or the project documentation.

## Commands:
- [mark](#mark)
- [scan](#scan)
- [del](#del)
- [code](#code)
- [new](#new)

---

### mark

**Flags:**  
- `-ongoing`: Mark the project as ongoing  
- `-finished`: Mark the project as finished  
- `-unfinished`: Mark the project as unfinished  

**Syntax:**  
```plaintext
mark [project name] [flag]
```

**Description:**  
Change the project status.

---

### scan

**Flags:**  
- `-cmd`: Display the project data on the command line  
- `-web`: Display the project data on the website  

**Syntax:**  
```plaintext
scan [flag]
scan [query] [flag]
```

**Description:**  
Display the project data on the command line or website based on the given query and flags.

---

### del

**Flags:**  
- none

**Syntax:**  
```plaintext
del [project name]
```

**Description:**  
Delete the project folder.

---

### code

**Flags:**  
- none

**Syntax:**  
```plaintext
code
code [project name]
```

**Description:**  
Open the VSCode editor of the current ongoing or specified project.

---

### new

**Flags:**  
- `-local`: Create a new project folder locally  
- `-github`: Create a new project folder on GitHub  

**Syntax:**  
```plaintext
new [flag] [project name]
```

**Description:**  
Create a new project folder.


# Credentials

Author: IzanamiiDevv </br>
Language: C++ </br>
License: MIT License </br>
Copyright (c) 2024 IzanamiiDevv. All rights reserved.