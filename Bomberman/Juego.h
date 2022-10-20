#pragma once
#include "Controlador.h"

namespace Bomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Juego
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{
	public:
		CControlador *oControlador = new CControlador();
		Bitmap^ bmpSolido = gcnew Bitmap("Imagenes\\bmpSolido.png");
		Bitmap^ bmpDestruible = gcnew Bitmap("Imagenes\\bmpDestruible.png");
		Bitmap^ bmpSuelo = gcnew Bitmap("Imagenes\\bmpSuelo.png");
		Juego(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Juego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 366);
			this->Name = L"Juego";
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		oControlador->dibujar(buffer->Graphics, bmpSuelo, bmpSolido, bmpDestruible);
		buffer->Render(g);
		delete buffer, espacio, g;
	}

	private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {
		oControlador->CambiarNivel();
	}
	};
}
