#include "syscall.h"

int main(void)
{
	int i, fid;
	int success= Create("file0.test");
	if (success != 1) MSG("Failed on creating file");
	for(i = 0; i < 5; i++) {
        fid = Open("file0.test");
        if (fid < 0) MSG("Failed on opening file");
        success = Close(fid);
        if (success != 1) MSG("Failed on closing file");
	}
	for(i = 0; i < 22; i++) {
        fid = Open("file0.test");
        if (fid < 0) MSG("Failed on opening file");
	}
	MSG("Success on creating file0.test");
	Halt();
}

