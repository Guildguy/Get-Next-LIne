## 📄 Get Next Line

### Description
Get Next Line is a project that challenges the student to write a C function capable of reading and returning a full line from a file descriptor (which may refer to a file, standard input, etc.), one line at a time, even when the line does not fit into a single read buffer.

### Challenges and Implementation

- **Data Persistence**  
  The main challenge was managing partial reads that exceeded the buffer size. This was elegantly solved using static variables to preserve state between function calls.

- **File Descriptor Handling**  
  Managing reads from multiple file descriptors simultaneously (bonus part, although my focus was on the mandatory requirements) required careful logic.

- **Read Optimization**  
  Balancing buffer size to optimize reading performance.

### What I Learned

- **Static Variables**  
  In-depth understanding of the use and behavior of static variables in C.

- **Input/Output (I/O) in C**  
  Handling file descriptors and the process of reading data from different sources.

- **Buffer Management**  
  Strategies for storing and processing data in chunks.
