#include <SDL3/SDL.h>
#include <glad/gl.h>

#include <iostream>

int main(){
    if (!SDL_Init(SDL_INIT_VIDEO)){
        std::cerr << "SDL Initialization failed: " << SDL_GetError() << '\n';
        return 1;

    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_PROFILE_MASK, 
        SDL_GL_CONTEXT_PROFILE_CORE
    );


    SDL_Window* window = SDL_CreateWindow("Alien Planet", 1280, 720, SDL_WINDOW_OPENGL);
    
    if (!window) {
        std::cerr << "Window creation failed: "
                  << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }
    
    
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if(!context){
        std::cerr <<"OpenGL context creation failed: " << SDL_GetError() << '\n';

        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;


    }
    if (!gladLoadGL(reinterpret_cast<GLADloadfunc>(SDL_GL_GetProcAddress))){
        std::cerr << "GLAD initialization failed.\n" << SDL_GL_DestroyContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;


    }

    std::cout  << "openGL version: " << reinterpret_cast<const char*>(glGetString(GL_VERSION)) <<'\n';
    
    bool running = true;
    SDL_Event event;

    while (running){
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_EVENT_QUIT) {
                running  = false;

            }

        }
        glClearColor(0.025f, 0.035f, 0.07f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);

    }
    SDL_GL_DestroyContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
    
}