void printf(char* str)
{
    static unsigned short* VideoMemory = (unsigned short*)0xb8000;

    for(int i = 0; str[i] != '\0'; ++i)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}

void ecranToutVert()
{
    static unsigned short* VideoMemory = (unsigned short*)0xb8000;
    const int nbDeMachinsSurEcran = 80*2*25;

    for(int i = 0; i < nbDeMachinsSurEcran; ++i)
        VideoMemory[i] = 0x2500;
    
}



typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}



extern "C" void kernelMain(const void* multiboot_structure, unsigned int /*multiboot_magic*/)
{
    ecranToutVert();
    printf("craignOS v0.0001");

    while(true)
    {
        printf("craignOS v0.0001");
    };
}