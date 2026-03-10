Создать и оформить формы:
1) Форма авторизации:
	- Поля ввода логина и пароля;
	- Кнопка завершения работы;
	- Кнопка входа;
	- Обработчики: динамический ввод (TextChanged), нажатие на кнопку "вход", нажатие кнопки "выход", завершение программы;
	- Свободное оформление дизайна;

2) Форма "Ежедневник":
	- Размер окна формы: 800x500;
	- Задний фон в виде изображения;
	- Создать вкладки через TabControl - каждая вкладка - заметка;
	- Создать панель функций ToolStrip - функции создание и удаление заметок;




using System;
using System.Windows.Forms;

namespace DailyPlanner
{
    public partial class LoginForm : Form
    {
        public LoginForm()
        {
            InitializeComponent();
            // Подписываемся на события TextChanged
            txtUsername.TextChanged += TxtUsername_TextChanged;
            txtPassword.TextChanged += TxtPassword_TextChanged;
        }

        private void TxtUsername_TextChanged(object sender, EventArgs e)
        {
            UpdateLoginButtonState();
        }

        private void TxtPassword_TextChanged(object sender, EventArgs e)
        {
            UpdateLoginButtonState();
        }

        private void UpdateLoginButtonState()
        {
            btnLogin.Enabled = !string.IsNullOrEmpty(txtUsername.Text) &&
                              !string.IsNullOrEmpty(txtPassword.Text);
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            if (AuthenticateUser(txtUsername.Text, txtPassword.Text))
            {
                lblStatus.Text = "Авторизация успешна!";
                lblStatus.ForeColor = System.Drawing.Color.



partial class LoginForm
{
    private System.ComponentModel.IContainer components = null;
    private TextBox txtUsername;
    private TextBox txtPassword;
    private Button btnLogin;
    private Button btnExit;
    private Label lblStatus;

    protected override void Dispose(bool disposing)
    {
        if (disposing && (components != null))
        {
            components.Dispose();
        }
        base.Dispose(disposing);
    }

    private void InitializeComponent()
    {
        this.txtUsername = new TextBox();
        this.txtPassword = new TextBox();
        this.btnLogin = new Button();
        this.btnExit = new Button();
        this.lblStatus = new Label();

        // txtUsername
        this.txtUsername.Location = new System.Drawing.Point(150, 80);
        this.txtUsername.Size = new System.Drawing.Size(200, 20);

        // txtPassword
        this.txtPassword.Location = new System.Drawing.Point(150, 120);
        this.txtPassword.Size = new System.Drawing.Size(200, 20);
        this.txtPassword.PasswordChar = '*';

        // btnLogin
        this.btnLogin.Location = new System.Drawing.Point(150, 160);
        this.btnLogin.Size = new System.Drawing.Size(90, 30);
        this.btnLogin.Text = "Вход";
        this.btnLogin.Click += new EventHandler(this.btnLogin_Click);

        // btnExit
        this.btnExit.Location = new System.Drawing.Point(260, 160);
        this.btnExit.Size = new System.Drawing.Size(90, 30);
        this.btnExit.Text = "Выход";
        this.btnExit.Click += new EventHandler(this.btnExit_Click);

        // lblStatus
        this.lblStatus.Location = new System.Drawing.Point(150, 200);
        this.lblStatus.Size = new System.Drawing.Size(200, 20);

        // LoginForm
        this.ClientSize = new System.Drawing.Size(500, 300);
        this.Controls.AddRange(new Control[] {
            this.txtUsername, this.txtPassword,
            this.btnLogin, this.btnExit, this.lblStatus
        });
        this.Text = "Авторизация";
    }
}


using System;
using System.Windows.Forms;

namespace DailyPlanner
{
    public partial class DailyPlannerForm : Form
    {
        public DailyPlannerForm()
        {
            InitializeComponent();
        }

        private void tsBtnNewNote_Click(object sender, EventArgs e)
        {
            var tabPage = new TabPage($"Заметка {tabControlNotes.TabCount + 1}");
            var textBox = new TextBox
            {
                Multiline = true,
                Dock = DockStyle.Fill,
                ScrollBars = ScrollBars.Vertical
            };
            tabPage.Controls.Add(textBox);
            tabControlNotes.TabPages.Add(tabPage);
            tabControlNotes.SelectedTab = tabPage;
        }

        private void tsBtnDeleteNote_Click(object sender, EventArgs e)
        {
            if (tabControlNotes.TabCount > 0)
            {
                tabControlNotes.TabPages.Remove(tabControlNotes.SelectedTab);
            }
        }
    }
}
partial class DailyPlannerForm
{
    private System.ComponentModel.IContainer components = null;
    private TabControl tabControlNotes;
    private ToolStrip toolStrip1;
    private ToolStripButton tsBtnNewNote;
    private ToolStripButton tsBtnDeleteNote;

    protected override void Dispose(bool disposing)
    {
        if (disposing && (components != null))
        {
            components.Dispose();
        }
        base.Dispose(disposing);
    }

    private void InitializeComponent()
    {
        this.tabControlNotes = new TabControl();
        this.toolStrip1 = new ToolStrip();
        this.tsBtnNewNote = new ToolStripButton();
        this.tsBtnDeleteNote = new ToolStripButton();

        // toolStrip1
        this.toolStrip1.Items.AddRange(new ToolStripItem[] {
            this.tsBtnNewNote, this.tsBtnDeleteNote
        });
        this.toolStrip1.Location = new System.Drawing.Point(0, 0);
        this.toolStrip1.Size = new System.Drawing.Size(800, 25);

        // tsBtnNewNote
        this.tsBtnNewNote.Text = "Новая заметка";
        this.tsBtnNewNote.Click += new EventHandler(this.tsBtnNewNote_Click);

        // tsBtnDeleteNote
        this.tsBtnDeleteNote.Text = "Удалить заметку";
        this.tsBtnDeleteNote.Click += new EventHandler(this.tsBtnDeleteNote_Click);

        // tabControlNotes
        this.tabControlNotes.Dock = DockStyle.Fill;

        // DailyPlannerForm
        this.ClientSize = new System.Drawing.Size(800, 500);
        this.Controls.AddRange
