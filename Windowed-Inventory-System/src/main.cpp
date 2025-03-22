//Libries to include
#include <raylib.h>
#include <iostream>
// Classes to include
#include "inventory.h"

//Main class
int main() 
{
    //vars for window
    int window_size[2];
    window_size[0] = 1200;
    window_size[1] = 600;

    InitWindow(window_size[0], window_size[1], "RAYLIB Inventory program");
    Texture2D stashTab{LoadTexture("/Textures/Inventory_Interface/Card X3/inventoryTab.png")};
    Vector2 stashPos{0.0, 0.0};
    const float stashScale{5.0f};



    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(stashTab, stashPos, 0.0, stashScale, WHITE);


        EndDrawing();

    }
    
    CloseWindow();
}