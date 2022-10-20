#pragma once
#include "Controladora.h"

namespace JuegoBomberman { 
    
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    

    /// <summary>
    /// 
    /// </summary>

   public ref class Juego : public System::Windows::Forms::Form {
    public:
        CControladora *oControladora = new CControladora
        Juego(void) {
            InitializeComponent();
            // código del
            // constructor
            // acá...
        }
   }
}

#pragma endregion

