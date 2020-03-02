/* ascii to hexString ��ascii�ַ���ת����hex�ַ��� "35"->"33 35" */
QString SerialAssistant::asciiToHexString(QString src)
{
    QByteArray buf;
    buf = src.toLocal8Bit();    // "35" -> 0x33 0x35
    buf = buf.toHex().toUpper();// 0x33 0x35 -> 0x33 0x35
    buf = this->insertSpace(buf );
    return QString::fromLocal8Bit(buf);// 0x33 0x35 -> "33 35"
}
/* hexString to ascii ��hex�ַ���ת����ascii�ַ��� "33 35"->"35" */
QString SerialAssistant::hexStringToAscii(QString src)
{
    QByteArray buf = stringToSend(src ,true);// "33 35"   -> 0x33 0x35
    return QString::fromLocal8Bit(buf);      // 0x33 0x35 -> "35"
}