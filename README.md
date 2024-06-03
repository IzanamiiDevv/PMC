# Project Manager CLI - PMC

**Help you to organize your Projects Directory**

## Overview

The Project Manager CLI is a powerful tool designed to help you efficiently manage your project directories. Whether you need to create, delete, mark, or open projects, this command-line interface provides simple and intuitive commands to streamline your workflow. Below are the available commands and their usage.

### Download
Click here to [Download](https://youtube.com)

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