#include "triwindow.h"
#include "ui_triwindow.h"

triwindow::triwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::triwindow)
{
    ui->setupUi(this);
    this->initManagerAccount="123456";
    this->initManagerPassword="000000";
    setWindowTitle("管理员端");
    connect(ui->backPushButton,QPushButton::clicked,this,this->sendShowSignal);
    ui->numberSpinBox->setMinimum(1);
    ui->numberSpinBox->setMaximum(5);
    this->model = new QSqlTableModel(this);//一个数据库表可视化模型
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);   // 设置编辑策略为手动提交
    model->setTable("journey");
    model->setHeaderData(0, Qt::Orientation::Horizontal, "序号");
    model->setHeaderData(1, Qt::Orientation::Horizontal, "身份证号");
    model->setHeaderData(2, Qt::Orientation::Horizontal, "姓名");
    model->setHeaderData(3, Qt::Orientation::Horizontal, "始发省份");
    model->setHeaderData(4, Qt::Orientation::Horizontal, "始发城市");
    model->setHeaderData(5, Qt::Orientation::Horizontal, "终点省份");
    model->setHeaderData(6, Qt::Orientation::Horizontal, "终点城市");
    model->setHeaderData(7, Qt::Orientation::Horizontal, "席别");
    model->setHeaderData(8, Qt::Orientation::Horizontal, "始发时间");
    model->setHeaderData(9, Qt::Orientation::Horizontal, "价格");
    model->setHeaderData(10, Qt::Orientation::Horizontal, "购票时间");
    model->select();//显示数据库表
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);    // 设置编辑策略
    ui->tableView->setModel(model);//显示模型的位置
    ui->stackedWidget_2->setCurrentIndex(0);
}

triwindow::~triwindow()
{
    delete ui;
}

QString triwindow::getInitManagerAccount()const
{
    return this->initManagerAccount;
}

QString triwindow::getInitManagerPassword()const
{
    return this->initManagerPassword;
}

void triwindow::sendShowSignal()
{
    emit showForm();
}

void triwindow::on_addPushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void triwindow::on_deletePushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    QMessageBox::information(this,"提示","删除后请点击保存\n但保存后不可恢复",QMessageBox::Ok);
}

void triwindow::on_searchPushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void triwindow::on_modifyPushButton_clicked()
{
    QMessageBox::information(this,"提示","请直接在右侧列表中进行修改\n然后点击保存",QMessageBox::Ok);
}

void triwindow::on_statisticPushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(5);
}

void triwindow::on_startProvince_currentTextChanged(const QString &arg1)
{
    if(arg1=="北京"){
        QStringList beijingCity;
        beijingCity<<"北京";
        ui->startCity->clear();
        ui->startCity->addItems(beijingCity);
    }
    if(arg1=="河北"){
        QStringList hebeiCity;
        hebeiCity<<"石家庄"<<"保定"<<"秦皇岛";
        ui->startCity->clear();
        ui->startCity->addItems(hebeiCity);
    }
}

void triwindow::on_endProvince_currentTextChanged(const QString &arg1)
{
    if(arg1=="北京"){
        QStringList beijingCity;
        beijingCity<<"北京";
        ui->endCity->clear();
        ui->endCity->addItems(beijingCity);
    }
    if(arg1=="河北"){
        QStringList hebeiCity;
        hebeiCity<<"石家庄"<<"保定"<<"秦皇岛";
        ui->endCity->clear();
        ui->endCity->addItems(hebeiCity);
    }
}

void triwindow::on_addPushButton_2_clicked()
{
    bool ismatch=true;
    for(int i=0;i<this->model->rowCount();++i){
        if(this->model->record(i).value(1)==ui->passengerId->text()&&this->model->record(i).value(2)!=ui->passengerName->text()){
            ismatch=false;
        }
    }
    if(ui->calendarWidget->selectedDate()<QDate::currentDate()){
        QMessageBox::warning(this,"错误","添加的购票记录已过期",QMessageBox::Cancel);
    }else if(ui->passengerName->text()==NULL){
        QMessageBox::warning(this,"错误","您未填写购票人姓名",QMessageBox::Cancel);
    }else if(ui->passengerId->text()==NULL){
        QMessageBox::warning(this,"错误","您未填写购票人身份证号",QMessageBox::Cancel);
    }else if(ui->startCity->currentText()==NULL){
        QMessageBox::warning(this,"错误","您未选择始发城市",QMessageBox::Cancel);
    }else if(ui->endCity->currentText()==NULL){
        QMessageBox::warning(this,"错误","您未选择终点城市",QMessageBox::Cancel);
    }else if(ui->startCity->currentText()==ui->endCity->currentText()){
        QMessageBox::warning(this,"错误","您选择的始发站和终点站相同",QMessageBox::Cancel);
    }else if(!ismatch){
        QMessageBox::warning(this,"错误","您的购票人姓名与身份证号不匹配",QMessageBox::Cancel);
    }else{
        for(int i=ui->numberSpinBox->text().toInt();i!=0;--i){
            QString id=ui->passengerName->text();
            QString name=ui->passengerId->text();
            QString startPro=ui->startProvince->currentText();
            QString startCity=ui->startCity->currentText();
            QString endPro=ui->endProvince->currentText();
            QString endCity=ui->endCity->currentText();
            QString seat=ui->seatComboBox->currentText();
            QString startTime=ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
            int price;
            switch(ui->seatComboBox->currentIndex()){
            case 0:
                price=150;
                break;
            case 1:
                price=300;
                break;
            case 2:
                price=50;
                break;
            case 3:
                price=500;
            }
            QString purchaseTime=QDate::currentDate().toString("yyyy-MM-dd");
            int row=model->rowCount();
            model->insertRow(row);
            model->setData(model->index(row,1),id);
            model->setData(model->index(row,2),name);
            model->setData(model->index(row,3),startPro);
            model->setData(model->index(row,4),startCity);
            model->setData(model->index(row,5),endPro);
            model->setData(model->index(row,6),endCity);
            model->setData(model->index(row,7),seat);
            model->setData(model->index(row,8),startTime);
            model->setData(model->index(row,9),price);
            model->setData(model->index(row,10),purchaseTime);
            // 开始事务操作
            model->database().transaction();
            if (model->submitAll()) {
                model->database().commit(); //提交
                QMessageBox::information(this,"添加","添加购票记录成功",QMessageBox::Ok);
            } else {
                model->database().rollback(); //回滚
                QMessageBox::warning(this, tr("添加"),
                tr("数据库错误: %1").arg(model->lastError().text()));
            }
        }
    }
}

void triwindow::on_deletePushButton_2_clicked()
{
    int number=ui->deletLineEdit->text().toInt();
    this->model->setFilter(QObject::tr("number!='%1'").arg(number));
    this->model->select();
    this->deletList.append(number);
    QMessageBox::information(this,"删除","删除成功",QMessageBox::Ok);
}

void triwindow::on_recoverPushButton_clicked()
{
    this->model->setFilter(NULL);
    this->model->select();
    this->deletList.clear();
    QMessageBox::information(this,"恢复","恢复成功",QMessageBox::Ok);
}

void triwindow::on_savePushButton_clicked()
{
    for(int i=0;i<this->deletList.count();++i){
        QString sql=QString("delete from journey where number='%1'").arg(this->deletList.at(i));
        QSqlQuery query;
        query.exec(sql);
        model->submitAll();
    }
    model->submitAll();
    model->database().commit();
    this->deletList.clear();
    QMessageBox::information(this,"保存","保存成功",QMessageBox::Ok);
}

void triwindow::on_mannerComboBox_currentTextChanged(const QString &arg1)
{
    if(arg1=="身份证号"){
        ui->mannerLabel->setText("身份证号");
    }else{
        ui->mannerLabel->setText("姓名");
    }
}

void triwindow::on_searchPushButton_2_clicked()
{
    if(ui->mannerComboBox->currentText()=="身份证号"){
        int id=ui->searchLineEdit->text().toInt();
        this->model->setFilter(QObject::tr("id='%1'").arg(id));
        this->model->select();
        if(this->model->rowCount()==0){
            QMessageBox::information(this,"查询","查询内容为空",QMessageBox::Ok);
        }
    }else{
        QString name=ui->searchLineEdit->text();
        this->model->setFilter(QObject::tr("name='%1'").arg(name));
        this->model->select();
        if(this->model->rowCount()==0){
            QMessageBox::information(this,"查询","查询内容为空",QMessageBox::Ok);
        }
    }
}

void triwindow::on_showAll_clicked()
{
    this->model->setFilter(NULL);
    this->model->select();
}

void triwindow::on_statisticPushButton_2_clicked()
{
    int count=0;
    int price=0;
    int count1=0;//小于100
    int count2=0;//100-400
    int count3=0;//大于400
    int price1=0;//小于100
    int price2=0;//100-400
    int price3=0;//大于400

    for(int i=0;i<this->model->rowCount();++i){
        if(this->model->record(i).value(10)==ui->calendarWidget_3->selectedDate().toString("yyyy-MM-dd")){
            ++count;
            price+=this->model->record(i).value(9).toInt();
        }
    }
    ui->showAmountLabel->setText(QString::number(count)+"张");
    ui->showMoneyLabel->setText(QString::number(price)+"元");

    for(int i=0;i<this->model->rowCount();++i){
        if(this->model->record(i).value(9).toInt()<100){
            ++count1;
            price1+=this->model->record(i).value(9).toInt();
        }
        if(this->model->record(i).value(9).toInt()<=400&&this->model->record(i).value(9).toInt()>=100){
            ++count2;
            price2+=this->model->record(i).value(9).toInt();
        }
        if(this->model->record(i).value(9).toInt()>=400){
            ++count3;
            price3+=this->model->record(i).value(9).toInt();
        }
    }
    if(ui->priceComboBox->currentText()=="小于100元"){
        ui->showAmountLabel_2->setText(QString::number(count1)+"张");
        ui->showMoenyLabel_2->setText(QString::number(price1)+"元");
    }
    if(ui->priceComboBox->currentText()=="大于等于100元且小于等于400元"){
        ui->showAmountLabel_2->setText(QString::number(count2)+"张");
        ui->showMoenyLabel_2->setText(QString::number(price2)+"元");
    }
    if(ui->priceComboBox->currentText()=="大于400元"){
        ui->showAmountLabel_2->setText(QString::number(count3)+"张");
        ui->showMoenyLabel_2->setText(QString::number(price3)+"元");
    }
}
