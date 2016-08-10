#ifndef _WEATHER_NOTIFIER_H_INCLUDED_
#define _WEATHER_NOTIFIER_H_INCLUDED_

void check_weather();

#endif // _WEATHER_NOTIFIER_H_INCLUDED_

WEATHER NOTIFIER
小明是一名程序员, 为了体现对女朋友的关心, 小明决定写一个程序自动在天气变化时向女朋友手机上发送一条提醒信息
例如当天如果下雨, 则自动向她的手机上发送一条"今天下雨,记得带伞哦"
小明经过一番努力, 发现某网站提供如下两个API, 能够帮助他实现梦想:
GET http://api.com/weather-api?location={CityName}取指定城市的天气情况, 会返回sunny, rain等状态
POST http://api.com/sms-gateway?number={PhoneNumber}&content={Message}指定手机号发送短信

测试?
获取天气的API需要网络连接, 并且最近持续是晴天
发送短信的API同样需要网络连接, 并且还会收费


