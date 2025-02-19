#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void queryOpenAI(const QString &prompt);  // 向 OpenAI API 发送请求

private slots:
    void on_sendMsg_clicked();
    void onFinished(QNetworkReply *reply);  // 响应完成时的槽函数

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;  // 网络访问管理器
    QNetworkRequest request;
    QJsonObject fixedJson;

    QJsonObject createRequestBody(const QString &prompt);
    QString readApiKeyFromConfig();  // 读取配置文件中的API密钥

    void setupRequest();

    void handleResponse(QNetworkReply *reply);

    QString apiKey;
};
#endif // MAINWINDOW_H
