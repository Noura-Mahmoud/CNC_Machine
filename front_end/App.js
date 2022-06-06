import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, View,TouchableOpacity } from 'react-native';
import {ImageBackground } from 'react-native';

export default function App() {
//  :::::::::::::::::::::::::::::::::::::Shape Selection Fun :::::::::::::::::::::::::::::::::::::::::
async function selectShape(type)
{
  console.log(type)
  let response =await fetch('http://172.20.10.7:8090/val', {
    method: 'POST',
    headers: {
      Accept: 'application/json',
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({
     "val":type

    })
  }); 
}




  return (
    // <ImageBackground  source={require('./assets/bg.webp')} resizeMode='stretch' style={styles.container}>
    <View style={styles.container} >
      <Text style={styles.TextStyle}>CNC Shapes:</Text>
      <View style={{marginTop:80}}>
      <TouchableOpacity
            style={styles.buttonStyle}
            activeOpacity={0.5}
            onPress={() =>
              {selectShape("2")}}>
            <Text style={styles.buttonTextStyle}> Triangle</Text>
      </TouchableOpacity>
    <TouchableOpacity
            style={styles.buttonStyle}
            activeOpacity={0.5}
            onPress={() =>
              {selectShape("0")}}>
            <Text style={styles.buttonTextStyle}> Rectangle</Text>
          </TouchableOpacity>
          <TouchableOpacity
            style={styles.buttonStyle}
            activeOpacity={0.5}
            onPress={() =>
              {selectShape("1")}}>
            <Text style={styles.buttonTextStyle}> Cube</Text>
          </TouchableOpacity>
          </View>
    </View>
    // </ImageBackground>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
    height:"100%"
 
  },
  image:
  {
    flex: 1,
    justifyContent: "center",
    // backgroundColor:'#251e51'
  },
  buttonStyle: {
    backgroundColor: 'blue',
    borderWidth: 0,
    color: '#FFFFFF',
    borderColor: '#7DE24E',
    height: 50,
    alignItems: 'center',
    borderRadius: 30,
    // marginLeft: -35,
    marginTop: 30,
    marginBottom: 10,
    margin:'auto',
    justifyContent:'center',
    width:170
  },
  buttonTextStyle: {
    color: '#FFFFFF',
    paddingVertical: 10,
    fontSize: 18,
    fontWeight:'bold'
  },
  TextStyle:
  {
    color: 'black',
    // paddingVertical: 10,
    fontSize: 38,
    fontWeight:'bold',
    marginTop:-170

  }
});
