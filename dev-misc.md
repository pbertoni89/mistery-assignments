###### What is this declaration a general example of?

```c
struct s {
    int i;
    struct s* s1;
    struct s *s2;
};
```

1. a linked list
2. a binary tree
3. a stack
4. a node
`4`

###### When is memory for a variable allocated?

1. during its declaration
2. during its initialization
3. during all of its assignments
4. during its definition

##### What does the program shown below return?

```c
int main() {
    int a=1, b=2, c=3, d=4;
    int x
    if (a>b)

    if (b<c) x=b;
    else x=c;
    return(x);
}
```

1. 0
2. 1
3. 2
4. 3

###### A pointer to void, named vptr, has been set to point to a Floating point variable named g. What is a valid way to dereference vptr to assign its pointed value to a float variable named F later in the program?

```c
float g;
void *vptr=&g;
```

1. f=(float)*vptr;
2. f=*(float *)vptr;
3. f=*(float)vptr;
4. f=(float *)vptr;
`2`

###### Using the union declaration below, how many bytes of memory space will the data of this type occupy?

```c
union Cars {
    char make[20];
    char model[30];
    short year;
} car;
```

1. 32
2. 54
3. 52
4. 30
`52`

###### What is the value of the variable output at the end of this program?

```c
#include <stdio.h>
main() {
    3 char output [50];
    int x = 100011;
    sprintf (output, "%05d", x);
    int y = strlen(output);
    sprintf (output, "%05d", y);
}
```

1. 00005
2. 1000116
3. 1000100005
4. 00006

###### Given the following source code, which sentence is not true at all.

```c
#include <iostream>
#include <mutex>
#include <fstream>
#include <thread>
#include <vector>

constexpr int TRIALS = 100000;
std::mutex __mut;

auto cnt(int match) {
    int a, occ = 0;
    std::lock_guard<std::mutex> lk(__mut);
    std::ifstream ifs("./my.txt");
    while (ifs >> a)
        occ += (match == a);
    return occ;
}

void ser() {
    for (int i=0; i<TRIALS; i++)
        cnt(5);
}

void par() {
    std::vector<std::thread> vt;
    for (int i =0; i < TRIALS; i++)
        vt.emplace_back(cnt, 5);
    for (auto & t : vt)
        t.join();
}

int main() { ser(); par(); return 0; }
```

1. `lk` variable is inefficient in a `ser` call
2. `lk` variable is useless in a `par` call, because each thread mantains its own file handlers
3. by construction, `parallel` won't benefit in terms of speed
4. the range-based loop while joining threads is more efficient than index-based access to `vt` elements
