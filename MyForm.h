#pragma once
#include<vector>


namespace Project5 {

	using namespace System;
	using namespace System::Threading;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	struct ret // structure of 2 doubles to return y[i+1] and v[i+1] from R-K function
	{
		double y;
		double v;
	};
	ret y_n(double l, double f, double y, double v)
	{
		double dt = 0.02;
		double k1 = dt * v;
		double m1 = dt * (-v * l - Math::Pow(f, 2) * y);
		double k2 = dt * (v + m1 / 2);
		double m2 = dt * (-(v + m1 / 2) * l - Math::Pow(f, 2) * (y + k1 / 2));
		double k3 = dt * (v + m2 / 2);
		double m3 = dt * (-(v + m2 / 2) * l - Math::Pow(f, 2) * (y + k2 / 2));
		double k4 = dt * (v + m3);
		double m4 = dt * (-(v + m3) * l - Math::Pow(f, 2) * (y + k3));
		ret a;
		a.y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		a.v = v + (m1 + 2 * m2 + 2 * m3 + m4) / 6;
		return a;
	};


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ close_button;

	private: System::Windows::Forms::Button^ Solve_button;
	private: System::Windows::Forms::Button^ stop_button;
	private: System::Windows::Forms::Label^ f_label;
	private: System::Windows::Forms::Label^ k_label;
	private: System::Windows::Forms::TextBox^ f_box;
	private: System::Windows::Forms::TextBox^ k_box;
	private: System::Windows::Forms::PictureBox^ graph;
	private: System::Windows::Forms::PictureBox^ portrait;
	private: System::Windows::Forms::Label^ label_author;
	private: System::Windows::Forms::Button^ save_graph_button;
	private: System::Windows::Forms::Button^ portrait_save_button;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ t_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ y_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ y1_col;
	private: System::Drawing::Bitmap^ Img_graph;
	private: System::Drawing::Bitmap^ Img_portrait;
	private: Thread^ Solver;
	private: System::Windows::Forms::Label^ time_label;
	private: System::Windows::Forms::Label^ label_value;
	private: bool checker = true;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->close_button = (gcnew System::Windows::Forms::Button());
			this->Solve_button = (gcnew System::Windows::Forms::Button());
			this->stop_button = (gcnew System::Windows::Forms::Button());
			this->f_label = (gcnew System::Windows::Forms::Label());
			this->k_label = (gcnew System::Windows::Forms::Label());
			this->f_box = (gcnew System::Windows::Forms::TextBox());
			this->k_box = (gcnew System::Windows::Forms::TextBox());
			this->graph = (gcnew System::Windows::Forms::PictureBox());
			this->portrait = (gcnew System::Windows::Forms::PictureBox());
			this->label_author = (gcnew System::Windows::Forms::Label());
			this->save_graph_button = (gcnew System::Windows::Forms::Button());
			this->portrait_save_button = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->t_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->y_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->y1_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->time_label = (gcnew System::Windows::Forms::Label());
			this->label_value = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->saveFileDialog2 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graph))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->portrait))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// close_button
			// 
			this->close_button->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->close_button->Location = System::Drawing::Point(707, 522);
			this->close_button->Name = L"close_button";
			this->close_button->Size = System::Drawing::Size(75, 24);
			this->close_button->TabIndex = 0;
			this->close_button->Text = L"Выйти";
			this->close_button->UseVisualStyleBackColor = true;
			this->close_button->Click += gcnew System::EventHandler(this, &MyForm::Close_button_Click);
			// 
			// Solve_button
			// 
			this->Solve_button->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Solve_button->Location = System::Drawing::Point(12, 129);
			this->Solve_button->Name = L"Solve_button";
			this->Solve_button->Size = System::Drawing::Size(150, 26);
			this->Solve_button->TabIndex = 3;
			this->Solve_button->Text = L"Решить";
			this->Solve_button->UseVisualStyleBackColor = true;
			this->Solve_button->Click += gcnew System::EventHandler(this, &MyForm::Solve_button_Click);
			// 
			// stop_button
			// 
			this->stop_button->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->stop_button->Location = System::Drawing::Point(165, 129);
			this->stop_button->Name = L"stop_button";
			this->stop_button->Size = System::Drawing::Size(150, 26);
			this->stop_button->TabIndex = 4;
			this->stop_button->Text = L"Остановить";
			this->stop_button->UseVisualStyleBackColor = true;
			this->stop_button->Click += gcnew System::EventHandler(this, &MyForm::Stop_button_Click);
			// 
			// f_label
			// 
			this->f_label->AutoSize = true;
			this->f_label->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->f_label->Location = System::Drawing::Point(70, 69);
			this->f_label->Name = L"f_label";
			this->f_label->Size = System::Drawing::Size(134, 16);
			this->f_label->TabIndex = 5;
			this->f_label->Text = L"Собственная частота";
			// 
			// k_label
			// 
			this->k_label->AutoSize = true;
			this->k_label->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->k_label->Location = System::Drawing::Point(53, 100);
			this->k_label->Name = L"k_label";
			this->k_label->Size = System::Drawing::Size(152, 16);
			this->k_label->TabIndex = 6;
			this->k_label->Text = L"Коэффициент затухания";
			// 
			// f_box
			// 
			this->f_box->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->f_box->Location = System::Drawing::Point(210, 69);
			this->f_box->Name = L"f_box";
			this->f_box->Size = System::Drawing::Size(50, 22);
			this->f_box->TabIndex = 7;
			this->f_box->Text = L"10";
			this->f_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->f_box->TextChanged += gcnew System::EventHandler(this, &MyForm::F_box_TextChanged);
			// 
			// k_box
			// 
			this->k_box->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->k_box->Location = System::Drawing::Point(210, 99);
			this->k_box->Name = L"k_box";
			this->k_box->Size = System::Drawing::Size(50, 22);
			this->k_box->TabIndex = 8;
			this->k_box->Text = L"2";
			this->k_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->k_box->TextChanged += gcnew System::EventHandler(this, &MyForm::K_box_TextChanged);
			// 
			// graph
			// 
			this->graph->BackColor = System::Drawing::SystemColors::Window;
			this->graph->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->graph->Location = System::Drawing::Point(402, 22);
			this->graph->Name = L"graph";
			this->graph->Size = System::Drawing::Size(380, 230);
			this->graph->TabIndex = 10;
			this->graph->TabStop = false;
			// 
			// portrait
			// 
			this->portrait->BackColor = System::Drawing::SystemColors::Window;
			this->portrait->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->portrait->Location = System::Drawing::Point(402, 271);
			this->portrait->Name = L"portrait";
			this->portrait->Size = System::Drawing::Size(380, 230);
			this->portrait->TabIndex = 11;
			this->portrait->TabStop = false;
			// 
			// label_author
			// 
			this->label_author->AutoSize = true;
			this->label_author->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_author->Location = System::Drawing::Point(106, 13);
			this->label_author->Name = L"label_author";
			this->label_author->Size = System::Drawing::Size(117, 18);
			this->label_author->TabIndex = 12;
			this->label_author->Text = L"Maksim Parnyakov";
			// 
			// save_graph_button
			// 
			this->save_graph_button->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->save_graph_button->Location = System::Drawing::Point(402, 522);
			this->save_graph_button->Name = L"save_graph_button";
			this->save_graph_button->Size = System::Drawing::Size(103, 24);
			this->save_graph_button->TabIndex = 13;
			this->save_graph_button->Text = L"Сохранить y(t)";
			this->save_graph_button->UseVisualStyleBackColor = true;
			this->save_graph_button->Click += gcnew System::EventHandler(this, &MyForm::Save_graph_button_Click);
			// 
			// portrait_save_button
			// 
			this->portrait_save_button->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->portrait_save_button->Location = System::Drawing::Point(511, 522);
			this->portrait_save_button->Name = L"portrait_save_button";
			this->portrait_save_button->Size = System::Drawing::Size(190, 24);
			this->portrait_save_button->TabIndex = 14;
			this->portrait_save_button->Text = L"Сохранить фазовый портрет";
			this->portrait_save_button->UseVisualStyleBackColor = true;
			this->portrait_save_button->Click += gcnew System::EventHandler(this, &MyForm::Portrait_save_button_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			dataGridViewCellStyle7->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::DodgerBlue;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle7;
			this->dataGridView1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::MintCream;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle8->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle8->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle8;
			this->dataGridView1->ColumnHeadersHeight = 30;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->t_col,
					this->y_col, this->y1_col
			});
			this->dataGridView1->GridColor = System::Drawing::Color::LightGray;
			this->dataGridView1->Location = System::Drawing::Point(12, 178);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle9->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle9;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 25;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(303, 368);
			this->dataGridView1->TabIndex = 15;
			// 
			// t_col
			// 
			this->t_col->HeaderText = L"t";
			this->t_col->Name = L"t_col";
			this->t_col->ReadOnly = true;
			this->t_col->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// y_col
			// 
			this->y_col->HeaderText = L"y";
			this->y_col->Name = L"y_col";
			this->y_col->ReadOnly = true;
			this->y_col->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// y1_col
			// 
			this->y1_col->HeaderText = L"y\'";
			this->y1_col->Name = L"y1_col";
			this->y1_col->ReadOnly = true;
			this->y1_col->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// time_label
			// 
			this->time_label->AutoSize = true;
			this->time_label->BackColor = System::Drawing::Color::Transparent;
			this->time_label->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->time_label->ForeColor = System::Drawing::Color::Black;
			this->time_label->Location = System::Drawing::Point(742, 252);
			this->time_label->Name = L"time_label";
			this->time_label->Size = System::Drawing::Size(40, 14);
			this->time_label->TabIndex = 16;
			this->time_label->Text = L"Время";
			// 
			// label_value
			// 
			this->label_value->AutoSize = true;
			this->label_value->BackColor = System::Drawing::Color::Transparent;
			this->label_value->Location = System::Drawing::Point(341, 129);
			this->label_value->Name = L"label_value";
			this->label_value->Size = System::Drawing::Size(55, 13);
			this->label_value->TabIndex = 17;
			this->label_value->Text = L"Значение";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"Точечный рисунок |*.bmp";
			// 
			// saveFileDialog2
			// 
			this->saveFileDialog2->Filter = L"Точечный рисунок |*.bmp";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(715, 501);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Координата";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(341, 390);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Скорость";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(333, 21);
			this->label3->TabIndex = 20;
			this->label3->Text = L"y\'\' + ky\' + f ^2 y = 0    y\'(0) = 0   y(0) = 1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(834, 558);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label_value);
			this->Controls->Add(this->time_label);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->portrait_save_button);
			this->Controls->Add(this->save_graph_button);
			this->Controls->Add(this->label_author);
			this->Controls->Add(this->portrait);
			this->Controls->Add(this->graph);
			this->Controls->Add(this->k_box);
			this->Controls->Add(this->f_box);
			this->Controls->Add(this->k_label);
			this->Controls->Add(this->f_label);
			this->Controls->Add(this->stop_button);
			this->Controls->Add(this->Solve_button);
			this->Controls->Add(this->close_button);
			this->Name = L"MyForm";
			this->Text = L"Ex 6 : Parnyakov Maksim";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graph))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->portrait))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Close_button_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try {
				if (checker == false)
					Solver->Resume();
				Solver->Abort();
			}
			catch (...) {}
			Application::Exit();
		}
private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	try {
		if (checker == false)
			Solver->Resume();
		Solver->Abort();
	}
	catch (...) {}
}
private: System::Void K_box_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			Single T;
			if (Single::TryParse(k_box->Text,
				System::Globalization::NumberStyles::Number,
				System::Globalization::NumberFormatInfo::CurrentInfo, T) == false && k_box->Text != "")
			{ 
					MessageBox::Show("Ввод данных произведен неверно!\n\nВведите неотрицательные вещественное число.", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
					k_box->Text = "2";
			}
		}
private: System::Void F_box_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			Single T_1;
			if (Single::TryParse(f_box->Text,
				System::Globalization::NumberStyles::Number,
				System::Globalization::NumberFormatInfo::CurrentInfo, T_1) == false && f_box->Text != "")
			{
				MessageBox::Show("Ввод данных произведен неверно!\n\nВведите неотрицательные вещественное число.", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
				f_box->Text = "10";
			}
		}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
	Img_graph = gcnew Bitmap(graph->Width, graph->Height);
	Graphics^ fill_g = Graphics::FromImage(Img_graph);
	Img_portrait = gcnew Bitmap(portrait->Width, portrait->Height);
	Graphics^ fill_p = Graphics::FromImage(Img_portrait);
	Brush^ fill_brush = gcnew SolidBrush(Color::White);
	fill_g->FillRectangle(fill_brush, Rectangle(0, 0, graph->Width, graph->Height));
	fill_p->FillRectangle(fill_brush, Rectangle(0, 0, portrait->Width, portrait->Height));
	dataGridView1->BeginInvoke(gcnew DelegateSetRow(this, &MyForm::SetRow), 0.0, 1.0, 0.0);
	stop_button->Enabled = false;
	save_graph_button->Enabled = false;
	portrait_save_button->Enabled = false;
	}
private: System::Void Solve_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
	if(k_box->Text == "")
		MessageBox::Show("Коэффициент затухания неопределен", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else
	{
		if(f_box->Text == "")
			MessageBox::Show("Собственная частота неопределена", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
		{
			Solve_button->Enabled = false;
			k_box->Enabled = false;
			f_box->Enabled = false;
			stop_button->Enabled = true;
			Solver = gcnew Thread(gcnew ThreadStart(this, &MyForm::solution));
			Solver->Start();
		}
	}
	
	} // Solving eq-n in separated thread
public: void solution() // Method to solve equation
	{
		std::vector<double> t;
		std::vector<double> y;
		std::vector<double> v;
		t.push_back(0);
		y.push_back(1.0);
		v.push_back(0.0);
		ret res;
		double y_coef, x_coef, max_y(-1e65), min_y(1e65);
		int counter = 0;
		while(true)
		{
			//stop_button->BeginInvoke(gcnew DelegateSetEnabled(this, &MyForm::SetEnabledButton), false);
			counter += 1;
			t.push_back(t[counter-1] + 0.02);
			res = y_n(Convert::ToDouble(k_box->Text), Convert::ToDouble(f_box->Text), y[counter - 1], v[counter - 1]);
			y.push_back(res.y);
			v.push_back(res.v);
			int axis_finder_max;
			int axis_finder_min;

			if (v[counter] > max_y)
			{
				max_y = v[counter];
				axis_finder_max = counter;
			}
			if (v[counter] < min_y)
			{
				min_y = v[counter];
				axis_finder_min = counter;
			}
			if (y[counter] > max_y)
			{
				max_y = y[counter];
				axis_finder_max = counter;
			}
			if (y[counter] < min_y)
			{
				min_y = y[counter];
				axis_finder_min = counter;
			}
			y_coef = Convert::ToDouble(graph->Height) / (max_y - min_y);
			x_coef = Convert::ToDouble(graph->Width) / t[counter];
			array<double>^ y_sc = gcnew array<double>(counter + 1);
			array<double>^ v_sc = gcnew array<double>(counter + 1);
			array<double>^ t_sc = gcnew array<double>(counter + 1);
			array<double>^ y_non_sc = gcnew array<double>(counter + 1);
			array<double> ^ v_non_sc = gcnew array<double>(counter + 1);
			for (int i = 0; i <= counter; i++)
			{
				y_non_sc[i] = y[i];
				v_non_sc[i] = v[i];
				y_sc[i] = y[i] * y_coef + Convert::ToDouble(graph->Height) - max_y * y_coef;
				v_sc[i] = v[i] * y_coef + Convert::ToDouble(graph->Height) - max_y * y_coef;
				t_sc[i] = t[i] * x_coef;
			}
			array<Object^>^ parms = gcnew array<Object^> {y_sc, v_sc, t_sc , counter, 
				Math::Max(y[axis_finder_max], v[axis_finder_max]) * y_coef + Convert::ToDouble(graph->Height) - max_y * y_coef,
				Math::Min(y[axis_finder_min], v[axis_finder_min]) * y_coef + Convert::ToDouble(graph->Height) - max_y * y_coef,
				Math::Max(y[axis_finder_max], v[axis_finder_max]), 
				Math::Min(y[axis_finder_min], v[axis_finder_min]),
				t[counter]};
			array<Object^>^ parms_1 = gcnew array<Object^> { t[counter], y[counter], v[counter]};
			array<Object^>^ parms_2 = gcnew array<Object^> {y_non_sc, v_non_sc, counter};
			graph->BeginInvoke(gcnew DelegateDrawImg(this, &MyForm::Draw_img), parms);
			graph->BeginInvoke(gcnew DelegateDrawPortrait(this, &MyForm::Draw_port), parms_2);
			dataGridView1->BeginInvoke(gcnew DelegateSetRow(this, &MyForm::SetRow), parms_1);
			stop_button->BeginInvoke(gcnew DelegateSetEnabled(this, &MyForm::SetEnabledButton), true);
			Thread::Sleep(1);
		} 

	}
delegate void DelegateSetRow(double t, double y, double v);
delegate void DelegateSetEnabled(bool enabled);
delegate void DelegateDrawImg(array<double>^ y, array<double>^ v, array<double>^ t, int counter, double max, double min, double max_val, double min_val, double t_max);
delegate void DelegateDrawPortrait(array<double>^ y, array<double>^ v, int counter);
public: void SetEnabledButton(bool enabled)
{
	stop_button->Enabled = enabled;
}
public: void SetRow(double t, double y, double v)
	{
		dataGridView1->Rows->Add(Convert::ToString(t), Convert::ToString(y), Convert::ToString(v));
	}
public: void Draw_img(array<double>^ y, array<double>^ v, array<double>^ t, int counter, double max, double min, double max_val, double min_val, double t_max)
	{
	Graphics^ fill = Graphics::FromImage(Img_graph);
	Brush^ fill_brush = gcnew SolidBrush(Color::White);
	fill->FillRectangle(fill_brush, Rectangle(0, 0, graph->Width, graph->Height));
	Graphics^ trash_screen = this->graph->CreateGraphics();
	trash_screen->FillRectangle(fill_brush, Rectangle(0, 0, graph->Width, graph->Height));
	delete trash_screen;
	for (int i = 0; i < counter; i++)
	{
		Graphics^ line = Graphics::FromImage(Img_graph);
		Graphics^ line_screen = this->graph->CreateGraphics();
		Graphics^ line_screen_axis = this->graph->CreateGraphics();
		Graphics^ line_axis = Graphics::FromImage(Img_graph);

		line_screen_axis->TranslateTransform(Convert::ToDouble(graph->Width) - t[counter], 0.9 * Convert::ToDouble(graph->Height));
		line_axis->TranslateTransform(Convert::ToDouble(graph->Width) - t[counter], 0.9 * Convert::ToDouble(graph->Height));

		line->TranslateTransform(Convert::ToDouble(graph->Width) - t[counter], 0.9*Convert::ToDouble(graph->Height));
		line->ScaleTransform(1, -0.85);

		line_screen->TranslateTransform(Convert::ToDouble(graph->Width) - t[counter], 0.9*Convert::ToDouble(graph->Height));
		line_screen->ScaleTransform(1, -0.85);

		Pen ^ line_pen = gcnew Pen(Color::BlueViolet, 2);
		Pen^ line_pen_1 = gcnew Pen(Color::Orange, 2);
		Pen^ axis_pen = gcnew Pen(Color::Gray, 0.6);
		Brush^ font_brush = gcnew SolidBrush(Color::Gray);
		FontFamily^ ffWrite = gcnew FontFamily("Arial");
		System::Drawing::Font^ fntWrite = gcnew System::Drawing::Font(ffWrite,
			8.0F, FontStyle::Regular);
		//
		//lines horizontal
		//
		line_screen->DrawLine(axis_pen, Convert::ToSingle(t[0]), Convert::ToSingle(v[0]), Convert::ToSingle(graph->Width), Convert::ToSingle(v[0]));
		line_screen->DrawLine(axis_pen, Convert::ToSingle(t[0]), Convert::ToSingle(max), Convert::ToSingle(graph->Width), Convert::ToSingle(max));
		line_screen->DrawLine(axis_pen, Convert::ToSingle(t[0]), Convert::ToSingle(min), Convert::ToSingle(graph->Width), Convert::ToSingle(min));
		line->DrawLine(axis_pen, Convert::ToSingle(t[0]), Convert::ToSingle(v[0]), Convert::ToSingle(graph->Width), Convert::ToSingle(v[0]));
		line->DrawLine(axis_pen, Convert::ToSingle(t[0]), Convert::ToSingle(max), Convert::ToSingle(graph->Width), Convert::ToSingle(max));
		line->DrawLine(axis_pen, Convert::ToSingle(t[0]), Convert::ToSingle(min), Convert::ToSingle(graph->Width), Convert::ToSingle(min));
		//
		//label horizontal
		//
		line_screen_axis->DrawString("0", fntWrite, font_brush, Convert::ToSingle(3), Convert::ToSingle(-v[0]*0.9));
		line_screen_axis->DrawString(Convert::ToString(Math::Round(max_val, 2)), fntWrite, font_brush, Convert::ToSingle(t[0] + 3), Convert::ToSingle(-max*0.85));
		line_screen_axis->DrawString(Convert::ToString(Math::Round(min_val, 2)), fntWrite, font_brush, Convert::ToSingle(t[0] + 3), Convert::ToSingle(min));
		line_axis->DrawString("0", fntWrite, font_brush, Convert::ToSingle(3), Convert::ToSingle(-v[0] * 0.9));
		line_axis->DrawString(Convert::ToString(Math::Round(max_val, 2)), fntWrite, font_brush, Convert::ToSingle(t[0] + 3), Convert::ToSingle(-max * 0.85));
		line_axis->DrawString(Convert::ToString(Math::Round(min_val, 2)), fntWrite, font_brush, Convert::ToSingle(t[0] + 3), Convert::ToSingle(min));
		//
		//lines vertical
		//
		line_screen_axis->TranslateTransform(0, 0);
		line_axis->TranslateTransform(0, 0);
		line_screen_axis->DrawLine(axis_pen, Convert::ToSingle(t[counter]) * 0.5, Convert::ToSingle(0), Convert::ToSingle(t[counter]) * 0.5, -Convert::ToSingle(graph->Height));
		line_screen_axis->DrawLine(axis_pen, Convert::ToSingle(t[counter]) * 0.75, Convert::ToSingle(0), Convert::ToSingle(t[counter]) * 0.75, -Convert::ToSingle(graph->Height));
		line_screen_axis->DrawLine(axis_pen, Convert::ToSingle(t[counter]) * 0.25, Convert::ToSingle(0), Convert::ToSingle(t[counter]) * 0.25, -Convert::ToSingle(graph->Height));
		line_axis->DrawLine(axis_pen, Convert::ToSingle(t[counter]) * 0.5, Convert::ToSingle(0), Convert::ToSingle(t[counter]) * 0.5, -Convert::ToSingle(graph->Height));
		line_axis->DrawLine(axis_pen, Convert::ToSingle(t[counter]) * 0.75, Convert::ToSingle(0), Convert::ToSingle(t[counter]) * 0.75, -Convert::ToSingle(graph->Height));
		line_axis->DrawLine(axis_pen, Convert::ToSingle(t[counter]) * 0.25, Convert::ToSingle(0), Convert::ToSingle(t[counter]) * 0.25, -Convert::ToSingle(graph->Height));
		//
		//label vertical
		//
		line_screen_axis->DrawString(Convert::ToString(Math::Round(t_max * 0.5, 2)), fntWrite, font_brush, Convert::ToSingle(t[counter] * 0.5), Convert::ToSingle(-max * 0.9));
		line_screen_axis->DrawString(Convert::ToString(Math::Round(t_max * 0.75, 2)), fntWrite, font_brush, Convert::ToSingle(t[counter] * 0.75), Convert::ToSingle(-max * 0.9));
		line_screen_axis->DrawString(Convert::ToString(Math::Round(t_max * 0.25, 2)), fntWrite, font_brush, Convert::ToSingle(t[counter] * 0.25), Convert::ToSingle(-max * 0.9));
		line_axis->DrawString(Convert::ToString(Math::Round(t_max * 0.5, 2)), fntWrite, font_brush, Convert::ToSingle(t[counter] * 0.5), Convert::ToSingle(-max * 0.9));
		line_axis->DrawString(Convert::ToString(Math::Round(t_max * 0.75, 2)), fntWrite, font_brush, Convert::ToSingle(t[counter] * 0.75), Convert::ToSingle(-max * 0.9));
		line_axis->DrawString(Convert::ToString(Math::Round(t_max * 0.25, 2)), fntWrite, font_brush, Convert::ToSingle(t[counter] * 0.25), Convert::ToSingle(-max * 0.9));
		//
		//graphs drawing
		//
		line->DrawLine(line_pen, Convert::ToSingle(t[i]), Convert::ToSingle(y[i]), Convert::ToSingle(t[i + 1]), Convert::ToSingle(y[i + 1]));
		line->DrawLine(line_pen_1, Convert::ToSingle(t[i]), Convert::ToSingle(v[i]), Convert::ToSingle(t[i + 1]), Convert::ToSingle(v[i + 1]));
		line_screen->DrawLine(line_pen, Convert::ToSingle(t[i]), Convert::ToSingle(y[i]), Convert::ToSingle(t[i + 1]), Convert::ToSingle(y[i + 1]));
		line_screen->DrawLine(line_pen_1, Convert::ToSingle(t[i]), Convert::ToSingle(v[i]), Convert::ToSingle(t[i + 1]), Convert::ToSingle(v[i + 1]));
	}
	}
public: void Draw_port(array<double>^ y, array<double>^ v,  int counter)
{
	Graphics^ fill = Graphics::FromImage(Img_portrait);
	Brush^ fill_brush = gcnew SolidBrush(Color::White);
	fill->FillRectangle(fill_brush, Rectangle(0, 0, portrait->Width, portrait->Height));
	Graphics^ trash_screen = this->portrait->CreateGraphics();
	trash_screen->FillRectangle(fill_brush, Rectangle(0, 0, portrait->Width, portrait->Height));
	delete trash_screen;
	double max_y1(-1e65), min_y1(1e65), max_x1(-1e65), min_x1(1e65);
	for (int i = 0; i < counter; i++)
	{
		if (v[i] > max_y1)
			max_y1 = v[i];
		else if (v[i] < min_y1)
			min_y1 = v[i];
		if (y[i] > max_x1)
			max_x1 = y[i];
		else if (y[i] < min_x1)
			min_x1 = y[i];
	}
	double x_coef1 = Convert::ToDouble(portrait->Width) / (max_x1 - min_x1);
	double y_coef1 = Convert::ToDouble(portrait->Height) / (max_y1 - min_y1);

	array<double>^ v_scaled = gcnew array<double>(counter + 1);
	array<double>^ y_scaled = gcnew array<double>(counter + 1);

	for (int i = 0; i <= counter; i++)
	{
		v_scaled[i] = v[i] * y_coef1 + Convert::ToDouble(portrait->Height) - max_y1 * y_coef1;
		y_scaled[i] = y[i] * x_coef1;
	}
	for (int i = 0; i < counter; i++)
	{
		Graphics^ line1 = Graphics::FromImage(Img_portrait);
		Graphics^ line1_screen = this->portrait->CreateGraphics();
		Graphics^ line1_screen_axis_h = this->portrait->CreateGraphics();
		Graphics^ line1_axis_h = Graphics::FromImage(Img_portrait);

		line1->TranslateTransform((Convert::ToDouble(portrait->Width) - max_y1)/2, 0.9*Convert::ToDouble(portrait->Height));
		line1->ScaleTransform(0.85, -0.85);

		line1_screen->TranslateTransform((Convert::ToDouble(portrait->Width) - max_y1) / 2, 0.9*Convert::ToDouble(portrait->Height));
		line1_screen->ScaleTransform(0.85, -0.85);

		line1_screen_axis_h->TranslateTransform((Convert::ToDouble(portrait->Width) - max_y1) / 2, 0.9 * Convert::ToDouble(portrait->Height));
		line1_screen_axis_h->ScaleTransform(0.85, -0.85);

		line1_axis_h->TranslateTransform((Convert::ToDouble(portrait->Width) - max_y1) / 2, 0.9 * Convert::ToDouble(portrait->Height));
		line1_axis_h->ScaleTransform(0.85, -0.85);

		Pen ^ line1_pen = gcnew Pen(Color::DarkOliveGreen, 2);
		Pen^ axis_pen = gcnew Pen(Color::Gray, 0.6);
		Brush^ font_brush = gcnew SolidBrush(Color::Gray);
		FontFamily^ ffWrite = gcnew FontFamily("Arial");
		System::Drawing::Font^ fntWrite = gcnew System::Drawing::Font(ffWrite,
			10.0F, FontStyle::Regular);

		//
		//lines horizontal
		//
		line1_screen->DrawLine(axis_pen, - Convert::ToSingle(1.2 * max_x1 * x_coef1), 0.0,  Convert::ToSingle(1.2 * max_x1 * x_coef1), 0.0);
		line1_screen->DrawLine(axis_pen, - Convert::ToSingle(1.2 * max_x1 * x_coef1), Convert::ToSingle(max_y1* y_coef1 + Convert::ToDouble(portrait->Height) - max_y1 * y_coef1),  Convert::ToSingle(1.2 * max_x1 * x_coef1), Convert::ToSingle(max_y1 * y_coef1 + Convert::ToDouble(portrait->Height) - max_y1 * y_coef1));
		line1_screen->DrawLine(axis_pen, - Convert::ToSingle(1.2 * max_x1 * x_coef1), Convert::ToSingle(v_scaled[0]), Convert::ToSingle(1.2 * max_x1 * x_coef1), Convert::ToSingle(v_scaled[0]));
		line1->DrawLine(axis_pen, -Convert::ToSingle(1.2 * max_x1 * x_coef1), 0.0, Convert::ToSingle(1.2 * max_x1 * x_coef1), 0.0);
		line1->DrawLine(axis_pen, -Convert::ToSingle(1.2 * max_x1 * x_coef1), Convert::ToSingle(max_y1 * y_coef1 + Convert::ToDouble(portrait->Height) - max_y1 * y_coef1), Convert::ToSingle(1.2 * max_x1 * x_coef1), Convert::ToSingle(max_y1 * y_coef1 + Convert::ToDouble(portrait->Height) - max_y1 * y_coef1));
		line1->DrawLine(axis_pen, -Convert::ToSingle(1.2 * max_x1 * x_coef1), Convert::ToSingle(v_scaled[0]), Convert::ToSingle(1.2 * max_x1 * x_coef1), Convert::ToSingle(v_scaled[0]));
		//
		//label horizontal
		//
		line1_screen_axis_h->ScaleTransform(1, -1);
		line1_axis_h->ScaleTransform(1, -1);
		line1_screen_axis_h->DrawString("0", fntWrite, font_brush, -(max_x1 * x_coef1), -Convert::ToSingle(v_scaled[0]));
		line1_screen_axis_h->DrawString(Convert::ToString(Math::Round(min_y1, 2)), fntWrite, font_brush, -(max_x1 * x_coef1), 0.0);
		line1_screen_axis_h->DrawString(Convert::ToString(Math::Round(max_y1, 2)), fntWrite, font_brush, -(max_x1 * x_coef1), -Convert::ToSingle(max_y1 * y_coef1 + Convert::ToDouble(portrait->Height) - max_y1 * y_coef1));
		line1_axis_h->DrawString("0", fntWrite, font_brush, -(max_x1 * x_coef1), -Convert::ToSingle(v_scaled[0]));
		line1_axis_h->DrawString(Convert::ToString(Math::Round(min_y1, 2)), fntWrite, font_brush, -(max_x1 * x_coef1), 0.0);
		line1_axis_h->DrawString(Convert::ToString(Math::Round(max_y1, 2)), fntWrite, font_brush, -(max_x1 * x_coef1), -Convert::ToSingle(max_y1 * y_coef1 + Convert::ToDouble(portrait->Height) - max_y1 * y_coef1));
		//
		//lines vertical
		//
		line1_screen->DrawLine(axis_pen, 0.0, 0.0, 0.0, Convert::ToSingle(1.2 * portrait->Height));
		line1_screen->DrawLine(axis_pen, (max_x1 * x_coef1) / 2, 0.0, (max_x1 * x_coef1) / 2, Convert::ToSingle(1.2 * portrait->Height));
		line1_screen->DrawLine(axis_pen, -(max_x1 * x_coef1) / 2, 0.0, -(max_x1 * x_coef1) / 2, Convert::ToSingle(1.2 * portrait->Height));
		line1->DrawLine(axis_pen, 0.0, 0.0, 0.0, Convert::ToSingle(1.2 * portrait->Height));
		line1->DrawLine(axis_pen, (max_x1 * x_coef1) / 2, 0.0, (max_x1 * x_coef1) / 2, Convert::ToSingle(1.2 * portrait->Height));
		line1->DrawLine(axis_pen, -(max_x1 * x_coef1) / 2, 0.0, -(max_x1 * x_coef1) / 2, Convert::ToSingle(1.2 * portrait->Height));
		//
		//label vertical
		//
		line1_screen_axis_h->DrawString("0", fntWrite, font_brush, 0.0, Convert::ToSingle(8));
		line1_screen_axis_h->DrawString("0,5", fntWrite, font_brush, (max_x1 * x_coef1) / 2, Convert::ToSingle(8));
		line1_screen_axis_h->DrawString("-0,5", fntWrite, font_brush, -(max_x1 * x_coef1) / 2, Convert::ToSingle(8));
		line1_axis_h->DrawString("0", fntWrite, font_brush, 0.0, Convert::ToSingle(8));
		line1_axis_h->DrawString("0,5", fntWrite, font_brush, (max_x1 * x_coef1) / 2, Convert::ToSingle(8));
		line1_axis_h->DrawString("-0,5", fntWrite, font_brush, -(max_x1 * x_coef1) / 2, Convert::ToSingle(8));
		//
		// portrait drawing
		//
		line1->DrawLine(line1_pen, Convert::ToSingle(y_scaled[i]), Convert::ToSingle(v_scaled[i]), Convert::ToSingle(y_scaled[i + 1]), Convert::ToSingle(v_scaled[i + 1]));
		line1_screen->DrawLine(line1_pen, Convert::ToSingle(y_scaled[i]), Convert::ToSingle(v_scaled[i]), Convert::ToSingle(y_scaled[i + 1]), Convert::ToSingle(v_scaled[i + 1]));
	}
}
private: System::Void Stop_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
	if (stop_button->Text == "Остановить" && stop_button->Enabled == true)
		{
		Solver->Suspend();
		checker = false;
		stop_button->Text = "Возобновить";
		save_graph_button->Enabled = true;
		portrait_save_button->Enabled = true;
		}
	else if (stop_button->Text == "Возобновить" && stop_button->Enabled == true)
		{
		Solver->Resume();
		checker = true;
		save_graph_button->Enabled = false;
		portrait_save_button->Enabled = false;
		stop_button->Text = "Остановить";
		}
	}
private: System::Void Save_graph_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
	try
	{
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Bitmap^ Bmp = gcnew Bitmap(Img_graph);
			Bmp->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Bmp);
		}
	}
	catch (Exception ^ Ситуация)
	{
		MessageBox::Show(Ситуация->Message, "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	}
private: System::Void Portrait_save_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
	try
	{
		if (saveFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Bitmap^ Bmp = gcnew Bitmap(Img_portrait);
			Bmp->Save(saveFileDialog2->FileName, System::Drawing::Imaging::ImageFormat::Bmp);
		}
	}
	catch (Exception ^ Ситуация)
	{
		MessageBox::Show(Ситуация->Message, "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	}
};
}
