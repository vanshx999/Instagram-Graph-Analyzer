#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "usergraph.h"
#include "ui_mainwindow.h"

UserGraph graph;  // global graph object


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Add User
    connect(ui->btnAddUser, &QPushButton::clicked, this, [=]() {
        QString name = ui->inputUser->text().trimmed();
        if (name.isEmpty()) return;
        graph.addUser(name.toStdString());
        ui->comboUserA->addItem(name);
        ui->comboUserB->addItem(name);
        ui->outputBox->setPlainText("User '" + name + "' added.");
        graph.addUser(name.toStdString());        // ✅ Real variable
        drawGraph();
    });

    // Follow
    connect(ui->btnFollow, &QPushButton::clicked, this, [=]() {
        QString from = ui->comboUserA->currentText();
        QString to = ui->comboUserB->currentText();
        graph.addFollow(from.toStdString(), to.toStdString());
        ui->outputBox->setPlainText(from + " now follows " + to);
        drawGraph();
    });

    // Mutual Followers
    connect(ui->btnMutuals, &QPushButton::clicked, this, [=]() {
        auto a = ui->comboUserA->currentText().toStdString();
        auto b = ui->comboUserB->currentText().toStdString();
        auto mutuals = graph.getMutuals(a, b);
        QString result = "Mutual Followers:\n";
        for (const auto& user : mutuals)
            result += QString::fromStdString(user) + "\n";
        ui->outputBox->setPlainText(result);
    });

    // Suggestions
    connect(ui->btnSuggestions, &QPushButton::clicked, this, [=]() {
        auto user = ui->comboUserA->currentText().toStdString();
        auto suggestions = graph.suggestFriends(user);
        QString result = "Friend Suggestions:\n";
        for (const auto& s : suggestions)
            result += QString::fromStdString(s) + "\n";
        ui->outputBox->setPlainText(result);
    });

    // Influencers
    connect(ui->btnInfluencers, &QPushButton::clicked, this, [=]() {
        auto top = graph.getTopInfluencers();
        QString result = "Top Influencers:\n";
        for (const auto& inf : top)
            result += QString::fromStdString(inf) + "\n";
        ui->outputBox->setPlainText(result);
    });
    // Remove User
    connect(ui->btnRemoveUser, &QPushButton::clicked, this, [=]() {
        QString name = ui->comboUserA->currentText();
        graph.removeUser(name.toStdString());

        int indexA = ui->comboUserA->findText(name);
        int indexB = ui->comboUserB->findText(name);
        ui->comboUserA->removeItem(indexA);
        ui->comboUserB->removeItem(indexB);

        ui->outputBox->setPlainText("User '" + name + "' removed.");
    });

    // Unfollow
    connect(ui->btnUnfollow, &QPushButton::clicked, this, [=]() {
        QString from = ui->comboUserA->currentText();
        QString to = ui->comboUserB->currentText();
        graph.unfollow(from.toStdString(), to.toStdString());
        ui->outputBox->setPlainText(from + " no longer follows " + to);
    });
    // Save Graph
    connect(ui->btnSave, &QPushButton::clicked, this, [=]() {
        graph.saveToFile("graph.txt");
        ui->outputBox->setPlainText("Graph saved to graph.txt");
    });

    // Load Graph
    connect(ui->btnLoad, &QPushButton::clicked, this, [=]() {
        graph.loadFromFile("graph.txt");

        // Repopulate dropdowns
        ui->comboUserA->clear();
        ui->comboUserB->clear();
        for (const auto& user : graph.getAllUsers()) {
            QString name = QString::fromStdString(user);
            ui->comboUserA->addItem(name);
            ui->comboUserB->addItem(name);
        }

        ui->outputBox->setPlainText("Graph loaded from graph.txt");
    });
    scene = new QGraphicsScene(this);
    ui->graphView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::drawGraph() {
    scene->clear();
    nodePositions.clear();

    auto users = graph.getAllUsers();
    int radius = 40;
    int spacing = 120;
    int x = 50, y = 50;

    // Draw nodes
    for (const std::string& uname : users) {
        QString name = QString::fromStdString(uname);
        QPointF pos(x, y);
        QGraphicsEllipseItem* node = scene->addEllipse(x, y, radius, radius);
        scene->addText(name)->setPos(x + 10, y + 10);
        nodePositions[name] = QPointF(x + radius / 2, y + radius / 2);
        x += spacing;
        if (x > 500) { x = 50; y += spacing; }
    }

    // Draw follow edges
    for (const std::string& from : users) {
        auto follows = graph.getMutuals(from, from);  // actually returns who this user follows
        for (const std::string& to : follows) {
            QPointF a = nodePositions[QString::fromStdString(from)];
            QPointF b = nodePositions[QString::fromStdString(to)];
            scene->addLine(a.x(), a.y(), b.x(), b.y(), QPen(Qt::black));
        }
    }
}
