def hello():
    print("Hello from Python!")
   
def add(a,b):
    try:
        return str(int(a) + int(b))
    except ValueError as e:
        return f"Error: {str(e)}"