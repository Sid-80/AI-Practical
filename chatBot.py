import streamlit as st
from langchain.prompts import PromptTemplate
from langchain_google_genai import ChatGoogleGenerativeAI
import os
import getpass

from dotenv import load_dotenv, find_dotenv
_ = load_dotenv(find_dotenv()) 

if "GOOGLE_API_KEY" not in os.environ:
    os.environ["GOOGLE_API_KEY"] = getpass.getpass("AIzaSyAxV4BOBTSPjjzrbgawUT-N5tPlLlON8Sk")

def generateText(text):
    llm = ChatGoogleGenerativeAI(model="gemini-pro")
    result = llm.invoke(text)
    return result.content

def main():
    
    st.header('ChatBot is here!')

    text = st.text_input("Prompt")

    if(text != ""):
        st.subheader(generateText(text))

main()