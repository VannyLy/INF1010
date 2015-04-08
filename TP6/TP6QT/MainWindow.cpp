/********************************************************************************/
/*                                                                              */
/*  INF-1010 Lab 6 :                                                            */
/*  Interface Graphique et Exception                                      	  	*/
/*                                                                              */
/********************************************************************************/

#include "MainWindow.h"


// Ne pas changer. Constructeur
MainWindow::MainWindow() {
	index_ = -1;
	range_ = 255;
	image_label_size = QSize(3 * 160, 3 * 90);
	setMenu();
 	setUI();
	setConnection();
}

// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
void MainWindow::setSliderRange() {

	// Vous devez mettre le range du slider entre -255 et 255
	// Au départ, le slider doit être initilisé �  zéro
}

// Ne pas changer. Construit l'interface
void MainWindow::setUI() {
 
  	// Création des sliders
	empty_button_ = new QPushButton(this);
	empty_button_->setText("Empty List");

 	// Création de la combobox de quatres elements.
 	// Ils corrspondants aux opérations sur les images
	process_combobox_ = new QComboBox(this);
	process_combobox_->addItem("--"); // Simple copie == aucun traitement
	process_combobox_->addItem("Intensity");
	process_combobox_->addItem("Contrast");
 
 	// Création du slider
	slider_ = new QSlider(Qt::Horizontal);
	setSliderRange();

	// 
	list_paths_ = new QListWidget(this);

	// Création des deux labels affichant les images
	image_label_ = new QLabel;
	image_label_->setFixedSize(image_label_size);
	image_process_label_ = new QLabel;
	image_process_label_->setFixedSize(image_label_size);

	// Définition du layout
	QFrame* line_1 = new QFrame();
	line_1->setFrameShape(QFrame::HLine);
	QFrame* line_2 = new QFrame();
	line_2->setFrameShape(QFrame::HLine);
	QFrame* line_3 = new QFrame();
	line_3->setFrameShape(QFrame::VLine);

	QVBoxLayout *ctrl_layout = new QVBoxLayout;
	ctrl_layout->addWidget(empty_button_);
	ctrl_layout->addWidget(list_paths_);
	ctrl_layout->addWidget(line_1);
	ctrl_layout->addWidget(process_combobox_);
	ctrl_layout->addWidget(slider_);

	QVBoxLayout *display_layout = new QVBoxLayout;
	display_layout->addWidget(image_label_);
	display_layout->addWidget(line_2);
	display_layout->addWidget(image_process_label_);

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(ctrl_layout);
	mainLayout->addWidget(line_3);
	mainLayout->addLayout(display_layout);

	QWidget *widget = new QWidget;
	widget->setLayout(mainLayout);
	 
	setCentralWidget(widget);

	// Titre de l'application
	setWindowTitle("Image Processing ToolBox");
}

// Ne pas changer. Construit le menu
void MainWindow::setMenu() {
	// Action pour ouvrir les images
	open_action_ = new QAction(style()->standardIcon(QStyle::SP_MediaPlay), tr("Open"), this);
	// Ici on lui associe le shortcut "Ctrl+O"
	open_action_->setShortcut(tr("Ctrl+o"));
	
	exit_action_ = new QAction(tr("E&xit"), this);
	exit_action_->setShortcuts(QKeySequence::Quit);

	// On créer un menu, puis on lui ajoute les actions
	QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(open_action_);
	fileMenu->addSeparator();
	fileMenu->addAction(exit_action_);
}

// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
void MainWindow::setConnection() {
	
	// Le slot 'close()' est une méthode de la classe QMainWindow dont MainWindow derive
        connect(exit_action_, SIGNAL(triggered()), this, SLOT(close()));

	// Vous devez établir les connections entre les elements de l'interface et les méthodes slots.
	// 1. L'action 'open_action' doit être connectée au slot 'load()' en utlisant le signal 'triggered()'
	//    cf. la class QAction
        connect(open_action_, SIGNAL(triggered()), this, SLOT(load()));

	// 2. La combobox 'process_combobox_' doit être connectée au slot 'processImage()'. 
	//    Le signal est emit quand l'utlisateur change d'index, cf. class QComboBox
        connect(process_combobox_, SIGNAL(currentIndexChanged()), this,SLOT(processImage()));

	// 3. L slider 'slider_' doit être connecté au slot 'processImage()'. 
	//    Le signal est emit quand l'utlisateur change la valeur du slider, cf. class QSlider
        connect(slider_, SIGNAL(valueChanged(int)), this, SLOT(processImage()));

        // 4. Le bouton 'empty_butotn' doit être connecté au slot 'empty()'.
	//    Le signal est emis lorsque l'utilisateur clique sur le button, cf. class QButton
        connect(empty_button_, SIGNAL(clicked()), this, SLOT(empty()));

	// 5. Le QListWidget 'list_paths_' doit être connecté au slot 'setImage(QListWidgetItem*)'. 
	//    Le signal est emis lorsque l'utilisateur clique sur un des elements de la liste.
	//    cf. class QListWidget et QListWidgetItem
        connect(list_paths_, SIGNAL(item_clicked(QListWidgetItem*)), this, SLOT(setImage(QListWidgetItem*)));

}

// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
void MainWindow::checkImageValid(const QImage &image) const {

	// Vous devez verifier si l'image est valide, c'est �  dire si elle n'est pas nulle, cf. QImage
	// Cette fonction doit envoyer une expection de type 'ImageLoadingException'
    if(image.isNULL())
    {
        ImageLoadingException imageCorrompue("�Votre image est corrompue\n");
        throw imageCorrompue;
    }
}

// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
void MainWindow::checkImageAlreadyLoaded(const QImage &image) const {

	// Vous devez verifier si l'image est déj�  présente dans la liste, cf. QList
	// Cette fonction doit envoyer une expection de type 'ImageLoadingException'
    if(images_list_.constains(&image))
    {
        ImageLoadingException imageDejaChargee("�Votre image est d�ja charg�e\n");
        throw imageDejaChargee;
    }
}

// Ne pas changer. Ajoute les images �  la liste
void MainWindow::addImages() {
	// Ici on ouvre les images au format 'png' seulement
	QStringList files = QFileDialog::getOpenFileNames(this, "Open file(s)", "./", "Files (*.png)");
	
	// Dans le cas ou aucun ficher n'est chargé
	// On retourne
	if (files.size() == 0)
        return;

    // Sinon, on load les images et on les ajoute �  la liste
    // On update également la liste de paths
	for (int i = 0; i < files.size(); ++i)
	{
		QImage image(files[i]);
		checkImageValid(image);
		checkImageAlreadyLoaded(image);
		images_list_.append(image);
		list_paths_->addItem(files[i]);
	}

	// Affiche la première image de la liste
	setImage(0);
}
 
// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
void MainWindow::load() {

	// Vous devez gérer les exceptions de type 'ImageLoadingException' générées lors de l'ouverture des images
	// cf. méthodes addImages(), checkImageValid() et checkImageAlreadyLoaded()
	// Si une exception est générée, il faut alors faire appel �  la méthode showAlert() de 'ImageLoadingException' pour afficher l'erreur
		
    try
    {
        addImages();

    }
    catch (ImageLoadingException& erreur)
    {
        erreur.showAlert();
    }

}

// Ne pas changer. Vide la liste d'images et de paths
void MainWindow::empty() {
	if (images_list_.size() > 0)
	{
		images_list_.clear();
		list_paths_->clear();
	}
	setImage(-1);
}

// Ne pas changer. Affiche l'image �  l'index index
void MainWindow::setImage(int index) {

	if ((index >= 0) && (index < images_list_.size()))
	{
		index_ = index;
		QPixmap pic = QPixmap::fromImage(images_list_[index]);
		pic.scaledToWidth(image_label_size.width(),  Qt::FastTransformation);
		image_label_->setPixmap(pic);
		image_label_->setFixedSize(image_label_size);
	}

	else
	{
		index_ = -1;
		image_label_->clear();
		image_label_->setFixedSize(image_label_size);
	}

	processImage();
}

// Ne pas changer. Affiche l'image �  l'index de l'element de list_paths_ 
// Surcharge de 'setImage(int index)'
void MainWindow::setImage(QListWidgetItem* item) {

	// On récupère l'inde courant de QListWidget *list_paths_
	// via list_paths_->currentRow()
	setImage(list_paths_->currentRow());
}

// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
void MainWindow::processImageIntensity() {

	// Vous devez vérifier si le retour de la méthode 'intensity(...)' de la classe 'ImageProcessing' est valide (== 0).
	// Si ce n'est pas le cas, vous devez générer une exception de type 'ImageProcessingException'
	// Si l'intensité moyenne de l'image traitée est trop haute, alors 'intensity(...)' retourne 1
	// A l,inverse, si l'intensité moyenne est trop basse, la méthode retourne -1
	// Enfin, la méthode retourne 0 si l'intensité moyenne est correcte 

        int res = process_.intensity(slider_->value(), images_list_[index_], image_process_);
        if(res ==1)
        {
            ImageProcessingException erreurHauteIntensite("L'intensit� est trop grande.");
            throw erreurHauteIntensite;
        }
        if(res ==-1)
        {
            ImageProcessingException erreurBasseIntensite("L'intensit� est trop basse.");
            throw erreurBasseIntensite;
        }

}

// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
void MainWindow::processImageContrast() {

	// Vous devez vérifier si le retour de la méthode 'contraste(...)' de la classe 'ImageProcessing' est valide (== 0).
	// Si ce n'est pas le cas, vous devez générer une exception de type 'ImageProcessingException'
	// Si l'intensité moyenne de l'image traitée est trop haute, alors 'contraste(...)' retourne 1
	// A l,inverse, si l'intensité moyenne est trop basse, la méthode retourne -1
	// Enfin, la méthode retourne 0 si l'intensité moyenne est correcte 
	
        int res = process_.contrast(slider_->value(), images_list_[index_], image_process_);

        if(res == 1)
        {
            ImageProcessingException erreurHautContraste("Le constraste est trop grand.");
            throw erreurHautContraste;
        }
        if(res == -1)
        {
            ImageProcessingException erreurBasContraste("Le contraste est trop bas.");
            throw erreurBasContraste;
        }
}

// Ne pas changer. Traite l'image courrante et update l'affichage
void MainWindow::processImageAccordingToCombobox() {
	
	// Si la liste est vide, on génére une exception de type 'NoImageException'.
	if (index_ == -1)
		throw NoImageException();

	// Sinon on traite l'image
	int process = process_combobox_->currentIndex();
	switch (process)
	{
		// Pas d'opération, simple copie
		case 0:
			image_process_ = images_list_[index_];
		break;

		// Change l'intensité
		case 1:
			processImageIntensity();
		break;

		// Change le contraste
		case 2:
			processImageContrast();
		break;
	}
}

// !!!!!!!!!! A FAIRE !!!!!!!!!!!!
void MainWindow::processImage() {

	// Vous devez gérer les exceptions de type 'ImageProcessingException' générées lors du traitement des images, cf. méthodes processImageIntensity(), processImageContrast()
	// Si une exception est générée, il faut alors faire appel �  la méthode resetSlider(...) de 'ImageProcessingException' pour remettre le slider �  zero.
	// Il faut aussi gérer l'exception 'NoImageException' générée par la méthode 'processImageAccordingToCombobox()'.
	// Cette exception est générée si on essaie de traiter une image alors que la liste d'image est vide.
	// Le cas échéant, il faudra ne plus afficher l'image traitée, remettre le slider et le combobox �  zero en faisant appel �  'reset(...) de 'NoImageException
	// Enfin, si aucune exception n'est levée, 'image_process_label_->setPixmap(QPixmap::fromImage(image_process_));' met �  jour l'affichage du résultat du traitement


    bool erreurPresente = false;
    try
    {
        processImageIntensity();

    }
    catch (ImageLoadingException& erreur)
    {
        erreur.resetSlider(slider_);
        erreurPresente = true;
    }

    try
    {
        processImageContrast();

    }
    catch (ImageLoadingException& erreur)
    {
        erreur.resetSlider(slider_);
        erreurPresente = true;
    }

    try
    {
        processImageAccordingToCombobox();

    }
    catch (NoImageException& err)
    {
        err.reset(slider_,image_process_label_,process_combobox_);
        erreurPresente = true;
    }


    // Update l'affichage de l'image traitée si aucune exception est n'générée
    if (!erreurPresente)
            image_process_label_->setPixmap(QPixmap::fromImage(image_process_));

}

