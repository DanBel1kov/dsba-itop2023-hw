#include "WindowController.h"


WindowController::WindowController(QStackedWidget *stackedWidget, const QList<Anime *> &listOfAnime, const QStringList &allGenres, Anime *selectedAnime): stackedWidget(stackedWidget)
{
    mainWindow = new MainWindow(listOfAnime, allGenres);
    detailedWindow = new DetailedWindow(selectedAnime);
    addAnimeWindow = new AddAnimeWindow();
    _selectedAnime = selectedAnime;
    connect(mainWindow, &MainWindow::openDetailedWindow, this, &WindowController::switchToSecondWindow);
    connect(detailedWindow, &DetailedWindow::openMainWindow, this, &WindowController::switchToMainWindow);
    connect(mainWindow, &MainWindow::openAddWindow, this, &WindowController::switchToAddWindow);
    connect(addAnimeWindow, &AddAnimeWindow::goToTheMainWindow, this, &WindowController::switchToMainWindow);
    connect(addAnimeWindow, &AddAnimeWindow::dataPassed, this, &WindowController::passToTheMainWindow);
//    connect(addAnimeWindow, &AddAnimeWindow::dataPassed, this, [this, mainWindow](Anime* anime) {
//        // Pass the data to the target window
//        mainWindow->model->appendRow(anime);
//        // Show the target window
//        // Hide or close the source window if needed
//        // ...
//    });
}

void WindowController::passToTheMainWindow(Anime* anime)
{
    mainWindow->setNewAnime(anime);
    stackedWidget->setCurrentWidget(mainWindow);

}
void WindowController::switchToSecondWindow()
{
    //detailedWindow = new DetailedWindow(_selectedAnime);
    _selectedAnime = mainWindow->getSelectedAnime();
    detailedWindow->setAnime(_selectedAnime);
    stackedWidget->setCurrentWidget(detailedWindow);
}

void WindowController::switchToMainWindow()
{
    stackedWidget->setCurrentWidget(mainWindow);
}

void WindowController::switchToAddWindow()
{
    stackedWidget->setCurrentWidget(addAnimeWindow);
}
