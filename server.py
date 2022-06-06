from urllib import response
from flask import Flask , request
from flask_cors import CORS
from flask import jsonify

# Create flask & cors instance 
app = Flask(__name__)
cors = CORS()
cors.init_app(app)

selected_shape = ["circle"]

previous_val = ["5"]

# Upadating srequired shape 
@app.route("/val",methods=["POST"])
def save_shape():
    shapes = request.get_json()
    selected_shape[0] = shapes["val"]
   # selected_shape[0] =x
   #  if x == "0": 
   #     selected_shape[0] = "square"
   
   #  elif x == "1":
   #     selected_shape[0] = "circle"
       
   #  elif x == "2":
   #     selected_shape[0] = "traingle"
        
   #  print(x)
   #  print("Drawing a " + selected_shape[0])
    return ("Drawing a " + selected_shape[0])
    
# Send required  shape 
@app.route('/draw_shape',methods=['GET'])
def draw_shape():
      #   response = jsonify(shape = selected_shape[0])
      #   response = jsonify(selected_shape[0])
    response= selected_shape[0]
    #   if (selected_shape[0] == previous_val[0]):
    #     print(5)
    #     return jsonify(5)
    #   else :
    #       previous_val[0] = selected_shape[0]
    print(response)
    return jsonify(response)
      
      
      #   print(response['shape'])
    #   print(response)
      
    #   return jsonify(response)


if __name__ == "__main__":
    app.run(host='0.0.0.0', port= 8090,debug=True)
