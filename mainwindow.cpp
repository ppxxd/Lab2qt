#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QLCDNumber>
#include <QGridLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);
    player->setAudioOutput(audio);

    slider = new QSlider(this);
    slider->setRange(0, 100);
    slider->setOrientation(Qt::Horizontal);

    ui->statusbar->addWidget(slider);
    ui->lcd->display("00:00:00");
    ui->lcd->setSegmentStyle(QLCDNumber::Outline);
    ui->statusbar->addWidget(ui->lcd);

    connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, slider, &QSlider::setValue);
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
    connect(slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);

    soundSlider = new QSlider(this);
    soundSlider->setOrientation(Qt::Horizontal);
    soundSlider->setSliderPosition(25);

    QLabel *label = new QLabel(ui->statusbar);
    QPixmap pixmap(QPixmap("/Users/andreykrutskikh/Desktop/Учеба/2 Курс/Прикладное программирование/lab2qt/Video_App/Icons/sound.png"));
    label->setPixmap(pixmap);

    ui->statusbar->addPermanentWidget(label);
    soundSlider->setRange(0,50);
    ui->statusbar->addPermanentWidget(soundSlider);
    connect(soundSlider, &QSlider::sliderMoved, audio, &QAudioOutput::volumeChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete player;
    delete audio;
    delete vw;
    delete slider;
    delete soundSlider;
}


void MainWindow::positionChanged(qint64 value){
    if(value/Fs < 600){
        if((value/Fs)%60 < 10){
            query = "0" + QString::number(value/(3600*Fs)) + ":0" + QString::number(value/(60*Fs)) + ":0" + QString::number((value/Fs)%60);
        }else{
            query = "0" + QString::number(value/(3600*Fs)) + ":0" + QString::number(value/(60*Fs)) + ":" + QString::number((value/Fs)%60);
        }
    }else{
        if(value/Fs < 10){
            query = "0" + QString::number(value/(3600*Fs)) + ":" + QString::number(value/(60*Fs)) + ":0" + QString::number((value/Fs)%60);
        }else{
            query = "0" + QString::number(value/(3600*Fs)) + ":" + QString::number(value/(60*Fs)) + ":" + QString::number((value/Fs)%60);
        }
    }
    if(!isPlaying){
        query = "00:00:00";
    }
    ui->lcd->display(query);
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a file", " " , "Video File (*.avi, *.mpg, *.mp4)");
    on_actionStop_triggered();

    player->setSource(QUrl::fromLocalFile(filename));

    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    player->setPlaybackRate(1.0);
    audio->setVolume(25);
    this->isPlaying = true;
}


void MainWindow::on_actionPause_triggered()
{
    player->pause();
    this->isPlaying = true;
}


void MainWindow::on_actionStop_triggered()
{
    player->stop();
    this->isPlaying = false;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


