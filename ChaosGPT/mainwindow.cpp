#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QDebug>
#define APIKey sk-OLmiedlzjRH2bGPQ4TOC0wXvt49qVgWEuifEbjAUzU6SZgCL


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 读取 API 密钥
    apiKey = readApiKeyFromConfig();
    if (apiKey.isEmpty()) {
        qWarning() << "API Key not found!";
    }
    qDebug()<<"APIKey="<<apiKey;
    manager = new QNetworkAccessManager(this);  // 初始化网络管理器
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::onFinished);  // 连接请求完成信号
    MainWindow::setupRequest();
    // 连接按钮点击事件到发送消息的槽函数
    connect(ui->sendMsg, &QPushButton::clicked, this, &MainWindow::on_sendMsg_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendMsg_clicked()
{
    QString prompt = ui->input->toPlainText();  // 获取输入框中的文本

    // 构建请求体
    QJsonObject json = createRequestBody(prompt);

    // 将 JSON 对象转换为字节数组
    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    // 发送 POST 请求
    manager->post(request, data);


    qDebug() << "Request URL: " << request.url();
    qDebug() << "Request Body: " << data;
}

void MainWindow::setupRequest()
{
    // 设置请求 URL 和请求头（这些通常是固定的）
    request.setUrl(QUrl("https://api.hunyuan.cloud.tencent.com/v1/chat/completions"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + apiKey.toUtf8());  // 使用读取的 API 密钥


    // 设置固定的 JSON 请求体部分（不变的部分）
    fixedJson["model"] = "hunyuan-turbo";
    fixedJson["max_tokens"] = 100;
}

QJsonObject MainWindow::createRequestBody(const QString &prompt)
{
    // 创建一个新的 JSON 对象，包含固定部分和动态变化的 prompt
    QJsonObject json = fixedJson;

    QJsonArray messages;

    // 创建一个 message 对象，包含 role 和 content
    QJsonObject message;
    message["role"] = "user";  // 用户角色
    message["content"] = prompt;  // 用户输入的内容

    // 将消息对象添加到 messages 数组中
    messages.append(message);

    json["messages"] = messages;

    return json;
}

void MainWindow::onFinished(QNetworkReply *reply)
{
    // 处理响应
    handleResponse(reply);
}

void MainWindow::handleResponse(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();  // 获取返回的响应数据

        qDebug() << "Response Data: " << responseData;  // 打印原始响应数据

        QJsonDocument doc = QJsonDocument::fromJson(responseData);
        QJsonObject obj = doc.object();

        //Decode
        QString text = obj["choices"].toArray().first().toObject()["message"].toObject()["content"].toString();

        qDebug() << "Decoded Response: " << text;  // 确保解码后的文本正确

        ui->input->clear();  // 清空输入框
        // 将返回的文本显示在输出框中
        ui->output->append(text);

    } else {
        // 处理错误
        qDebug() << "Error:" << reply->errorString();
        ui->output->setPlainText("Error: " + reply->errorString());
    }

    reply->deleteLater();  // 清理 reply 对象
}

QString MainWindow::readApiKeyFromConfig()
{
    QString configPath = QCoreApplication::applicationDirPath() + "/config.ini";
    QSettings settings(configPath, QSettings::IniFormat);
    return settings.value("API/key").toString();
}
