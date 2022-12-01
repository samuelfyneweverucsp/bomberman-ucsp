#pragma once

#include "Controlador.h"

namespace Bomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de JuegoMulti
	/// </summary>
	public ref class JuegoMulti : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ MusicaN;
		CControlador* oControlador = new CControlador();
		Bitmap^ bmpSolido = gcnew Bitmap("Imagenes\\bmpSolido.png");
		Bitmap^ bmpDestruible = gcnew Bitmap("Imagenes\\bmpDestruible.png");
		Bitmap^ bmpSuelo = gcnew Bitmap("Imagenes\\bmpSuelo.png");
		Bitmap^ bmpJugador1 = gcnew Bitmap("Imagenes\\Jugador.png");
		Bitmap^ bmpJugador2 = gcnew Bitmap("Imagenes\\Jugador2.png");
		Bitmap^ bmpBomba = gcnew Bitmap("Imagenes\\bomba.png");
		Bitmap^ bmpExplosion = gcnew Bitmap("Imagenes\\explosion.png");
		Bitmap^ bmpMejoras = gcnew Bitmap("Imagenes\\bmpMejoras.png");
	public:
		JuegoMulti(void)
		{
			bmpJugador1->MakeTransparent(bmpJugador1->GetPixel(0, 0)); // quitarle el fondo para hacerlo transparente
			bmpJugador2->MakeTransparent(bmpJugador2->GetPixel(0, 0));
			bmpBomba->MakeTransparent(bmpBomba->GetPixel(0, 0));
			bmpExplosion->MakeTransparent(bmpExplosion->GetPixel(0, 0));
			InitializeComponent();
			oControlador = new CControlador();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~JuegoMulti()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblNivel;
	private: System::Windows::Forms::ProgressBar^ pbCarga;
	private: System::Windows::Forms::Timer^ trCarga;
	private: System::Windows::Forms::Timer^ timer1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblNivel = (gcnew System::Windows::Forms::Label());
			this->pbCarga = (gcnew System::Windows::Forms::ProgressBar());
			this->trCarga = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &JuegoMulti::timer1_Tick);
			// 
			// lblNivel
			// 
			this->lblNivel->AutoSize = true;
			this->lblNivel->BackColor = System::Drawing::Color::Transparent;
			this->lblNivel->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNivel->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lblNivel->Location = System::Drawing::Point(212, 237);
			this->lblNivel->Name = L"lblNivel";
			this->lblNivel->Size = System::Drawing::Size(89, 35);
			this->lblNivel->TabIndex = 0;
			this->lblNivel->Text = L"Nivel:";
			// 
			// pbCarga
			// 
			this->pbCarga->Location = System::Drawing::Point(188, 300);
			this->pbCarga->Name = L"pbCarga";
			this->pbCarga->Size = System::Drawing::Size(161, 23);
			this->pbCarga->TabIndex = 1;
			// 
			// trCarga
			// 
			this->trCarga->Enabled = true;
			this->trCarga->Interval = 2500;
			this->trCarga->Tick += gcnew System::EventHandler(this, &JuegoMulti::trCarga_Tick);
			// 
			// JuegoMulti
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->ClientSize = System::Drawing::Size(848, 736);
			this->Controls->Add(this->pbCarga);
			this->Controls->Add(this->lblNivel);
			this->Name = L"JuegoMulti";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"JuegoMulti";
			this->Load += gcnew System::EventHandler(this, &JuegoMulti::JuegoMulti_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoMulti::MantenerTecla1);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoMulti::MantenerTecla2);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoMulti::UltimaTeclaPresionada1);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoMulti::UltimaTeclaPresionada2);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void MusicNivel() {
		MusicaN = gcnew SoundPlayer("Audio\\ModoSolitario.wav");
		MusicaN->PlayLooping();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		oControlador->dibujarMultiPlayer(buffer->Graphics, bmpSuelo, bmpSolido, bmpBomba, bmpExplosion, bmpDestruible,
										bmpJugador1, bmpJugador2, bmpMejoras);
		buffer->Render(g);
		delete buffer, espacio, g;
		this->Text = "" + oControlador->getoJugador1()->getVidas();
	}

	private: System::Void JuegoMulti_Load(System::Object^ sender, System::EventArgs^ e) {
		oControlador->CambiarNivel();
	}
	private: System::Void MantenerTecla1(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::W:
			oControlador->getoJugador1()->setDireccion(Direcciones::Arriba);
			break;
		case Keys::S:
			oControlador->getoJugador1()->setDireccion(Direcciones::Abajo);
			break;
		case Keys::A:
			oControlador->getoJugador1()->setDireccion(Direcciones::Izquierda);
			break;
		case Keys::D:
			oControlador->getoJugador1()->setDireccion(Direcciones::Derecha);
			break;
		default:
			break;
		}
	}

	private:
		System::Void UltimaTeclaPresionada1(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			switch (e->KeyCode) {
			case Keys::Space:
				oControlador->agregarBomba(oControlador->getoArrBombas1(), oControlador->getoJugador1());
				break;
			default:
				oControlador->getoJugador1()->setDireccion(Direcciones::Ninguna);
				break;
			}
		}
	private: System::Void MantenerTecla2(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Up:
			oControlador->getoJugador2()->setDireccion(Direcciones::Arriba);
			break;
		case Keys::Down:
			oControlador->getoJugador2()->setDireccion(Direcciones::Abajo);
			break;
		case Keys::Left:
			oControlador->getoJugador2()->setDireccion(Direcciones::Izquierda);
			break;
		case Keys::Right:
			oControlador->getoJugador2()->setDireccion(Direcciones::Derecha);
			break;
		default:
			break;
		}
	}

	private:
		System::Void UltimaTeclaPresionada2(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			switch (e->KeyCode) {
			case Keys::Enter:
				oControlador->agregarBomba(oControlador->getoArrBombas2(), oControlador->getoJugador2());
				break;
			default:
				oControlador->getoJugador2()->setDireccion(Direcciones::Ninguna);
				break;
			}
		}
	private: System::Void trCarga_Tick(System::Object^ sender, System::EventArgs^ e) {
		lblNivel->Text = "Nivel: " + oControlador->getNivel();
		pbCarga->Increment(10);
		if (trCarga->Interval == 2500 && oControlador->getoArrMejoras()->getvector_mejoras().size() < oControlador->getNivel()) {
			oControlador->crear_mejoras();
		}
		else {
			trCarga->Enabled = false;
			timer1->Enabled = true;
			MusicNivel();
			lblNivel->Visible = false;
			lblNivel->Enabled = false;
			pbCarga->Visible = false;
			pbCarga->Enabled = false;
		}
	}
#pragma endregion
	};
}
